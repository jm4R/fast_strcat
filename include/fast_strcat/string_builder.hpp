#include <iostream>
#include <string_view>
#include <tuple>
#include <string>

template<typename... Args>
struct string_builder
{
    std::tuple<Args&...> vals;

    template <typename T>
    constexpr auto operator<<(T& v) && -> string_builder<Args..., T>
    {
        return {std::tuple_cat(vals, std::tuple<T&>{v})};
    }

    constexpr operator std::string() &&
    {
        auto len = std::size_t{0};
        std::apply([&](auto&... x){  (len += ... += std::string_view{x}.length());  } , vals);

        auto res = std::string{};
        res.reserve(len);

        std::apply([&](auto&... x){  (res += ... += x);  } , vals);

        return res;
    }
};

constexpr auto build_string()
{
    return string_builder<>{};
}
