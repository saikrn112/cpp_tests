#include <iostream>

int main(int argc, char** argv)
{
    int a = 3;
    int b = ~a;//a << 1;
    std::cout << b << std::endl;
    std::bitset<8> c(b);
    std::cout << c << std::endl;
    return 0;
}
