#pragma once
#include <concepts>
#include <iterator>
#include <string_view>
#include <type_traits>

namespace oxenc {

template <typename T>
concept string_view_compatible = std::convertible_to<T, std::string_view> ||
                                 std::convertible_to<T, std::basic_string_view<unsigned char>> ||
                                 std::convertible_to<T, std::basic_string_view<std::byte>>;

template <typename Char>
concept basic_char = sizeof(Char) == 1 && !std::same_as<Char, bool> &&
                     (std::integral<Char> || std::same_as<Char, std::byte>);

using namespace std::literals;

inline std::string_view trim_prefix(std::string_view src, std::string_view prefix) noexcept {
    std::string_view result = src;
    if (result.starts_with(prefix))
        return result.substr(prefix.size());
    return result;
}
}  // namespace oxenc
