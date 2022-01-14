# FastStrcat

The header-only library that helps with single allocation std::basic_string building.

## Background
It is a bad idea to concatenate more than 2 strings by simple `std::basic_string::operator+`. Better idea is to call `std::basic_string::reserve` and then `std::basic_string::append` (or `std::basic_string::operator+=`). Such workflow allows us to avoid temporary objects allocation.

This library provides variadic version of `std::strcat`, `std::wcscat` and generic `std::basic_strcat` which does that for you.

## Using standalone functions:

```c++
//for std::string:
std::string makeUnixPath(const std::string& appPath, const std::string& graphPath, const std::string& fileName)
{
	return mj::strcat(appPath, "/", graphPath, "/", fileName);
}

//for std::wstring:
std::wstring makeUnixWPath(const std::wstring& appPath, const std::wstring& graphPath, const std::wstring& fileName)
{
	return mj::strcat(appPath, L"/", graphPath, L"/", fileName);
}

//for other std::basic_string:
std::u16string makeUnixWPath(const std::u16string& appPath, const std::u16string& graphPath, const std::u16string& fileName)
{
	using vt = u16string::value_type;
	return mj::basic_strcat<vt>(appPath, u"/", graphPath, u"/", fileName);
}
```

## Using string_builder

The `string_builder` class allows using stream-like syntax. It also allows using types that requires `std::to_string` conversion (only for `CharT == char`), like integers, floating-point values:

```c++
std::string makeProductId(const std::string& productName, int index)
{
    return mj::build_string() << productName << "_" << index;
}
```

