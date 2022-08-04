#include <iostream>
#include <array>
int main()
{
    std::array<int,32> arr;
    for (int i=0;i<10;i++)
    {
        arr[i] = i;
    }

    std::cout << sizeof(arr)/sizeof(arr[0]) << std::endl;
    std::cout << std::size(arr) << std::endl;

}
