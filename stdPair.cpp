#include <iostream>

std::pair<int,int>
func()
{
    return std::make_pair(1,1);
}
int main()
{
    std::pair<int,int> a (1,2);
    std::cout << a.first << " " << a.second << std::endl;
    auto A = func();
    std::cout << A.first << " " << A.second << std::endl;
}
