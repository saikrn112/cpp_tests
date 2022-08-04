#include <iostream>
#include <vector>

int main(int argv, char** argc)
{
    int a = 34;
    decltype (a) b = 90;
    std::vector<float> c;
    decltype (c)::value_type d = 03;
    //std::cout << (c)::value_type << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << type_name<decltype(a)> << std::endl;
    return 0;
}

