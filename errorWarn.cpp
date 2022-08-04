#include <iostream>
#include <vector>
int func()
{
    int a = 2;
    return a;
}
template <typename T>
int func2(T a)
{
    return a;
}

int main()
{
    func();
    func2<float>(2);
    unsigned int a = 1;
    int b = 2;
    bool ret = (a < b);
    std::vector<int> a1 = {1,2,3,5,6};
    for (int i = 0; i < a1.size(); i++)
    {
        std::cout << a1[i] << std::endl;
    }

}
