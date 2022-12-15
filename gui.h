#pragma once

#include "common.h"
#include "c_ressource.h"
#include "video.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

namespace sdl {
   using Window   = stdex::c_resource<SDL_Window, SDL_CreateWindow, SDL_DestroyWindow>;
   using Renderer = stdex::c_resource<SDL_Renderer, SDL_CreateRenderer, SDL_DestroyRenderer>;
   using Texture  = stdex::c_resource<SDL_Texture, SDL_CreateTexture, SDL_DestroyTexture>;
}

namespace gui {
struct tDimensions {
	uint16_t Width;
	uint16_t Height;
};

static const auto initializedSDL    = SDL_Init(SDL_INIT_VIDEO);
static constexpr auto TextureFormat = SDL_PIXELFORMAT_ARGB8888;

static constexpr bool successful(int Code) {
	return Code == 0;
}

static auto centeredBox(tDimensions Dimensions,
                        int Monitor = SDL_GetNumVideoDisplays()) noexcept {
	struct Box {
		int Width{0};
		int Height{0};
		int x = SDL_WINDOWPOS_CENTERED;
		int y = SDL_WINDOWPOS_CENTERED;
	} box{Dimensions.Width, Dimensions.Height};

	if (SDL_Rect Display; Monitor > 0 and successful(SDL_GetDisplayBounds(Monitor - 1, &Display))) 
   {
		box.Width  = std::min(Display.w, box.Width);
		box.Height = std::min(Display.h, box.Height);
		box.x      = Display.x + (Display.w - box.Width) / 2;
		box.y      = Display.y + (Display.h - box.Height) / 2;
	}

	return box;
}


// the most minimal GUI
// capable of showing a frame with some decor for user interaction
// renders the video frames
struct FancyWindow 
{
	explicit FancyWindow(tDimensions Dimensions) noexcept
   {
      const auto Viewport = centeredBox(Dimensions);

      Window_   = { "Look at me!",
               Viewport.x, Viewport.y, Viewport.Width, Viewport.Height,
                  SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN };
      Renderer_ = { Window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC };

      SDL_SetWindowMinimumSize(Window_, Viewport.Width, Viewport.Height);
      SDL_RenderSetLogicalSize(Renderer_, Viewport.Width, Viewport.Height);
      SDL_RenderSetIntegerScale(Renderer_, SDL_TRUE);
      SDL_SetRenderDrawColor(Renderer_, 240, 240, 240, 240);
   }

   void updateFrom(const video::FrameHeader & Header) noexcept 
   {
      video::PixelFormat f;
      if (not Header.isFirstFrame())
         return;

      if (Header.hasNoPixels()) 
      {
         SDL_HideWindow(Window_);
         Texture_ = {};

      } else {

         Width_        = Header.Width_;
         Height_       = Header.Height_;
         PixelsPitch_  = Header.LinePitch_;
         SourceFormat_ = Header.Format_ == to_underlying(video::PixelFormat::RGBA)
                           ? SDL_PIXELFORMAT_ABGR8888
                           : SDL_PIXELFORMAT_ARGB8888;

         // Texture_ = sdl::Texture(Renderer_, TextureFormat, SDL_TEXTUREACCESS_STREAMING,
         //                         Width_, Height_);

         SDL_SetWindowMinimumSize(Window_, Width_, Height_);
         SDL_RenderSetLogicalSize(Renderer_, Width_, Height_);
         SDL_ShowWindow(Window_);
      }
   }

   void present(video::tPixels Pixels) noexcept {
      void * TextureData;
      int TexturePitch;

      SDL_RenderClear(Renderer_);
      if (successful(SDL_LockTexture(Texture_, nullptr, &TextureData, &TexturePitch))) 
      {
         SDL_ConvertPixels(Width_, Height_, SourceFormat_, Pixels.data(), PixelsPitch_,
                           TextureFormat, TextureData, TexturePitch);
         SDL_UnlockTexture(Texture_);
         SDL_RenderCopy(Renderer_, Texture_, nullptr, nullptr);
      }
      SDL_RenderPresent(Renderer_);
   }

private:
	sdl::Window Window_;
	sdl::Renderer Renderer_;
	sdl::Texture Texture_;
	int Width_;
	int Height_;
	int PixelsPitch_;
	int SourceFormat_;
};

bool isAlive() noexcept {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return false;
	}
	return true;
}

}