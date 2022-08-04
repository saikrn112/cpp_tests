#include <iostream>
#include <vector>
#include <span>


template <typename T>
void f(std::span<T> data)
{
    std::for_each(data.begin(), data.end(), [](auto da){ std::cout << da << std::endl;});
}
int main(int argc, char** argv)
{
    std::vector<int> datas{1,2,3,4,5,6};
    std::span<int> data_span = datas;
    f(data_span);

}
