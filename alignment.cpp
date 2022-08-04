#include <iostream>

struct alignas(32) Foo
{
    uint32_t a;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    char b;
};

int main()
{
    auto a = new Foo();
    std::cout << alignof(Foo) << std::endl;
    std::cout << alignof(std::max_align_t) << std::endl;
}
