#include "console.h"

// mkdir build && cd build && cmake -A Win32 .. && cmake --build . --config Release

// cmake -G "Visual Studio 16 2019" -A Win32 -S \path_to_source\ -B "build32"
// cmake -G "Visual Studio 16 2019" -A x64 -S \path_to_source\ -B "build64"
// cmake --build build32 --config Release
// cmake --build build64 --config Release

#define _WIN32_WINNT 0x0A00
#include <asio.hpp>

auto main() -> int
{
    print("Contemporary C++\n");

    asio::io_context io;

    asio::steady_timer t(io, asio::chrono::seconds(5));

    t.wait();

    print("timer gone\n");




    return {};
    // Console app;
    // return app.run();
}
