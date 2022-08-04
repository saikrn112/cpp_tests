#include "tempClass.h"
int main(int argc, char** argv)
{
    std::cout << max(1,2) << std::endl;
    TestAutoReturn test(1.5,2.4);
    test.print();
    test.set(4.5,7.3);
    test.print();
    return 0;
}
