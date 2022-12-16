// #include "windows.h"

#include "console.h"

// cmake -A Win32 -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:\Packages\scripts\buildsystems\vcpkg.cmake
// && cmake --build .\build\ --config Release

// mkdir build && cd build && cmake -A Win32 .. && cmake --build . --config Release

// cmake -G "Visual Studio 16 2019" -A Win32 -S \path_to_source\ -B "build32"
// cmake -G "Visual Studio 16 2019" -A x64 -S \path_to_source\ -B "build64"
// cmake --build build32 --config Release
// cmake --build build64 --config Release

//    "dependencies": [
//       "asio",
//       "sdl2",
//      {
//       "name": "ffmpeg",
//       "default-features": false,
//       "features": [ "avcodec", "avformat" ]
//      }
//    ]


#define _WIN32_WINNT 0x0A00
#include <asio.hpp>


// #include <libavcodec/avcodec.h>
// #include <libavformat/avformat.h>

#include "gui.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

// static const char *filter_descr = "aresample=8000,aformat=sample_fmts=s16:channel_layouts=mono";
// static const char *player       = "ffplay -f s16le -ar 8000 -ac 1 -";

// static AVFormatContext *fmt_ctx;
// static AVCodecContext *dec_ctx;
// AVFilterContext *buffersink_ctx;
// AVFilterContext *buffersrc_ctx;
// AVFilterGraph *filter_graph;
// static int audio_stream_index = -1;

// AVCodecContext* pCodec;
// SDL_Window* pWindow;

// using WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;


auto main(int, char* []) -> int
{
    print("Contemporary C++\n");


    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(2));

    print("timer start\n");
    t.wait();
    print("timer gone\n");

    // AVFormatContext *pFormatContext = avformat_alloc_context();
    // if (!pFormatContext) {
    //     print("ERROR could not allocate memory for Format Context");
    //     return -1;
    // }

    // avcodec_alloc_context3(pCodec->codec);
    // avcodec_free_context(&pCodec);


    auto win = gui::FancyWindow({ .Width = 800, .Height = 600 });

    win.updateFrom({ .Width_ = 800, .Height_ = 600, .LinePitch_ = 1});
    win.present({});


    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // SDL_Window *window;                    // Declare a pointer

    // SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // // Create an application window with the following settings:
    // window = SDL_CreateWindow(
    //     "An SDL2 window",                  // window title
    //     SDL_WINDOWPOS_UNDEFINED,           // initial x position
    //     SDL_WINDOWPOS_UNDEFINED,           // initial y position
    //     640,                               // width, in pixels
    //     480,                               // height, in pixels
    //     SDL_WINDOW_OPENGL                  // flags - see below
    // );

    // // Check that the window was successfully created
    // if (window == NULL) {
    //     // In the case that the window could not be made...
    //     printf("Could not create window: %s\n", SDL_GetError());
    //     return 1;
    // }

    // // The window is open: could enter program loop here (see SDL_PollEvent())

    // SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // // Close and destroy the window
    // SDL_DestroyWindow(window);

    // // Clean up
    // SDL_Quit();

    return {};
    // Console app;
    // return app.run();
}
