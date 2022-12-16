#include "common.h"
#include "asio.h"
#include "gui.h"

// cmake -A Win32 -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:\Packages\scripts\buildsystems\vcpkg.cmake
// && cmake --build .\build\ --config Release

// mkdir build && cd build && cmake -A Win32 .. && cmake --build . --config Release

auto main(int, char* []) -> int
{
    print("Contemporary C++\n");


    asio::io_context io;
    asio::steady_timer timer(io, asio::chrono::seconds(2));

    print("timer start\n");
    timer.wait();
    print("timer gone\n");

    auto window = gui::FancyWindow({ .Width = 800, .Height = 600 });

    window.updateFrom({ .Width_ = 800, .Height_ = 600, .LinePitch_ = 1});
    window.present({});


    SDL_Delay(3000);
    SDL_Quit();

    return {};
}
