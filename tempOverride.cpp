#include <iostream>

class base
{
public:
    virtual void process(int a){std::cout << "base ver:" << a << std::endl;};
};

class derived
{
public:
    template <typename T>
    void process(T a) { std::cout << "derived ver:" << a << std::endl;}
};


int main()
{
    derived d1;
    base& b1 = (base&)d1;
    d1.process(1);
    b1.process(1);
}
