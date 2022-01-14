#ifndef jm4R_STRING_BUILDER
#define jm4R_STRING_BUILDER

#include "strcat.hpp"

#include <string>
#include <tuple>
#include <type_traits>

namespace mj {

template <typename CharT, typename... Args>
struct basic_string_builder
{
    std::tuple<Args...> vals;

    template <typename T>
    constexpr static bool needs_to_string =
        !std::is_constructible_v<std::basic_string_view<CharT>, T&>;

    template <typename T>
    constexpr auto operator<<(const T& v) && -> basic_string_builder<
        CharT, Args...,
        std::conditional_t<needs_to_string<T>, std::basic_string<CharT>,
                           const T&>>
    {
        if constexpr (!needs_to_string<T>)
            return {std::tuple_cat(vals, std::tuple<const T&>{v})};
        else
            return {std::tuple_cat(
                vals, std::tuple<std::basic_string<CharT>>{std::to_string(v)})};
    }

    constexpr operator std::basic_string<CharT>() &&
    {
        return std::apply(
            [&](auto&... vals) { return mj::basic_strcat<CharT>(vals...); },
            vals);
    }
};

template <typename... Args>
using string_builder = basic_string_builder<char, Args...>;

template <typename... Args>
using wstring_builder = basic_string_builder<wchar_t, Args...>;

template <typename CharT>
constexpr auto basic_build_string()
{
    return basic_string_builder<CharT>{};
}

constexpr auto build_string()
{
    return string_builder<>{};
}

constexpr auto build_wstring()
{
    return wstring_builder<>{};
}
}

#endif //jm4R_STRING_BUILDER
