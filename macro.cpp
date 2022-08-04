#include <iostream>
#define FUN(a,b) static void fun_##a##Delete() { std::cout << "I am here" << std::endl;};
#if defined(VAL) and VAL==DEBUG
    #define FUNC2 static void func2() {std::cout << "I am here" << std::endl;};
#else
    #define FUNC2 static void func2() {std::cout << "I am not here" << std::endl;};
#endif

FUN(3,2);
FUNC2;
int main()
{
    //fun_1_Delete();
    fun_3Delete();
    func2();
}
