#include <fast_strcat/strcat.hpp>
#include <fast_strcat/string_builder.hpp>

#include <cassert>

int main()
{
    std::string test2 = "test2";
    const char* test4 = "test4";
    std::string test = build_string() << "test1 " << test2 << " test3 " << test4;
    assert(test == "test1 test2 test3 test4");
	return 0;
}
