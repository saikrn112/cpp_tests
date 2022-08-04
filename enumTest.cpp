#include <iostream>
#include <type_traits>

enum class ab : uint16_t
{
    a = 0,
    l = 12,
    b, 
    c,
};

int main()
{
    ab a1 = ab::a;
    a1 = static_cast<ab>(2);
    switch(ab::c)
    {
        case ab::a: std::cout << "a:0" << std::endl;break;
        case ab::b: std::cout << "b:" << (uint8_t)ab::b << std::endl;break;
        case ab::c: std::cout << "c:" << static_cast<std::underlying_type<ab>::type>(ab::c) << std::endl;break;
        default: std::cout << "default hit" << std::endl;
    }

    return 0;
}
