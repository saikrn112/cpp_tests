#include <iostream>

struct C
{
    C() {}
    C(const C&) {std::cout << "A copy was made.\n";}
    void print() {std::cout << "Print was called\n";}
};


C f()
{
    return C();
}


int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    C obj = f();
    obj.print();
    return 0;
}
