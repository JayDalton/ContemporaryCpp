#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <format>
#include <fstream>
#include <filesystem>
#include <map>
#include <mutex>
#include <numeric>
#include <optional>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_set>
#include <unordered_map>
#include <variant>
#include <vector>

using String = std::string;
using StringList = std::vector<String>;
using StringOpt = std::optional<String>;
using StringView = std::string_view;

template <typename... Args>
void print(StringView format, Args&&... args)
{
   std::cout << std::vformat(format, std::make_format_args(args...));
}

using WString = std::wstring;
using WStringList = std::vector<WString>;
using WStringOpt = std::optional<WString>;
using WStringView = std::wstring_view;

template <typename... Args>
void print(WStringView format, Args&&... args)
{
   std::wcout << std::vformat(format, std::make_wformat_args(args...));
}

using namespace std::chrono_literals;
using namespace std::string_view_literals;

namespace fs = std::filesystem;
namespace rgs = std::ranges;
namespace vws = std::views;

namespace StringCharLiterals 
{
   // https://learn.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp

   using namespace std::string_view_literals;
   using namespace std::string_literals;

   // Character literals
   auto c0 =   'A'; // char
   auto c1 = u8'A'; // char
   auto c2 =  L'A'; // wchar_t
   auto c3 =  u'A'; // char16_t
   auto c4 =  U'A'; // char32_t

   // Multicharacter literals
   auto m0 = 'abcd'; // int, value 0x61626364

   // String literals
   auto s0 =   "hello"; // const char*
   auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                      // const char8_t* in C++20
   auto s2 =  L"hello"; // const wchar_t*
   auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
   auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32

   // Raw string literals containing unescaped \ and "
   auto R0 =   R"("Hello \ world")"; // const char*
   auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                   // const char8_t* in C++20
   auto R2 =  LR"("Hello \ world")"; // const wchar_t*
   auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
   auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

   // Combining string literals with standard s-suffix
   auto S0 =   "hello"s; // std::string
   auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
   auto S2 =  L"hello"s; // std::wstring
   auto S3 =  u"hello"s; // std::u16string
   auto S4 =  U"hello"s; // std::u32string

   // Combining raw string literals with standard s-suffix
   auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
   auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                    // std::u8string in C++20
   auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
   auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
   auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32

}