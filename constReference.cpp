#include <iostream>

class Obj
{
public:
    Obj() = default;
    Obj& operator = (const Obj& from) = default;
private:
    int a;
};

const Obj& createObj()
{
    
    return Obj();
}

int main()
{
    int a = 1;
    int const& b = a;
    std::cout << &a << " " << &b << std::endl;

    int c = 2;
    b = c;

}
