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
   int Monitor = SDL_GetNumVideoDisplays()) noexcept 
{
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
	explicit FancyWindow(tDimensions dimensions) noexcept
   {
      const auto viewport = centeredBox(dimensions);

      print("FancyWindow: {} {}\n", viewport.Height, viewport.Width);

      m_window = { 
         "Look at me!",
         viewport.x, viewport.y, 
         viewport.Width, viewport.Height,
         SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN 
      };

      m_renderer = { m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC };

      SDL_SetWindowMinimumSize(m_window, viewport.Width, viewport.Height);
      SDL_RenderSetLogicalSize(m_renderer, viewport.Width, viewport.Height);
      SDL_RenderSetIntegerScale(m_renderer, SDL_TRUE);
      SDL_SetRenderDrawColor(m_renderer, 40, 40, 40, 40);
   }

   void updateFrom(const video::FrameHeader & Header) noexcept 
   {
      if (not Header.isFirstFrame())
      {
         print("first empty");
         return;
      }

      if (Header.hasNoPixels()) 
      {
         print("frame empty");
         SDL_HideWindow(m_window);
         m_texture = {};

      } else {

         print("show frame");
         m_width        = Header.Width_;
         m_height       = Header.Height_;
         m_pixelPitch  = Header.LinePitch_;
         m_sourceFormat = Header.Format_ == to_underlying(video::PixelFormat::RGBA)
                           ? SDL_PIXELFORMAT_ABGR8888
                           : SDL_PIXELFORMAT_ARGB8888;

         // m_texture = sdl::Texture(m_renderer, TextureFormat, SDL_TEXTUREACCESS_STREAMING,
         //                         m_width, m_height);

         SDL_SetWindowMinimumSize(m_window, m_width, m_height);
         SDL_RenderSetLogicalSize(m_renderer, m_width, m_height);
         SDL_ShowWindow(m_window);
      }
   }

   void present(video::tPixels Pixels) noexcept {
      void * TextureData;
      int TexturePitch;

      SDL_RenderClear(m_renderer);
      if (successful(SDL_LockTexture(m_texture, nullptr, &TextureData, &TexturePitch))) 
      {
         SDL_ConvertPixels(m_width, m_height, m_sourceFormat, Pixels.data(), m_pixelPitch,
                           TextureFormat, TextureData, TexturePitch);
         SDL_UnlockTexture(m_texture);
         SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
      }
      SDL_RenderPresent(m_renderer);
   }

private:
	sdl::Window m_window;
	sdl::Renderer m_renderer;
	sdl::Texture m_texture;
	int m_width;
	int m_height;
	int m_pixelPitch;
	int m_sourceFormat;
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