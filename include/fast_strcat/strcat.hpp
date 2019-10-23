#ifndef jm4R_STRCAT
#define jm4R_STRCAT
#include <string>
#include <string_view>

namespace mj {

template <typename CharT, typename... Args>
constexpr std::basic_string<CharT> basic_strcat(const Args&... vals)
{
    auto len = std::size_t{ 0 };
    (len += ... += std::basic_string_view<CharT>{ vals }.length());
    auto res = std::basic_string<CharT>{};
    res.reserve(len);
    (res += ... += vals);
    return res;
}

template <typename... Args>
constexpr std::string strcat(const Args&... vals)
{
    return basic_strcat<std::string::value_type>(vals...);
}

template <typename... Args>
constexpr std::wstring wcscat(const Args&... vals)
{
    return basic_strcat<std::wstring::value_type>(vals...);
}
}

#endif //jm4R_STRCAT
