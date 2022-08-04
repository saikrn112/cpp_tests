#include <iostream>

void func0(char a)
{
    return;
}
template <typename T>
void func(T param)
{
    func0(param);
}

int main(void)
{
    const int a[] = {1,2,3,4};
    const int* b = nullptr;
    const char* const c = "fun with pointers";
    func(c);
    return 0;
}
