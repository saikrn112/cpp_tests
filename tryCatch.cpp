#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "constructed" << std::endl;
    }
    ~A()
    {
        std::cout << "destructed" << std::endl;
    }
};
int main()
{
    A();
    try
    {
        throw(1);
    }
    catch(...)
    {
        
    }
    return 0;
}
