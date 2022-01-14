#include <fast_strcat/strcat.hpp>
#include <fast_strcat/string_builder.hpp>

#include <cassert>

std::string makeProductId(const std::string& productName, int index)
{
    return mj::build_string() << productName << "_" << index;
}

int main()
{
    std::string test2 = "test2";
    const char* test4 = "test4";
    std::string test = mj::build_string() << 0 << "test1 " << test2 << " test3 " << test4 << 5;
    assert(test == "0test1 test2 test3 test45");
    assert(makeProductId("Apple", 6) == "Apple_6");

    assert(mj::strcat("a", "b ", test2) == "ab test2");
    assert(mj::strcat("a", std::to_string(5)) == "a5");

    assert(mj::wcscat(L"a", std::wstring{L"b"}, L"c") == L"abc");
	return 0;
}
