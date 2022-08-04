#include <iostream>

int main()
{
    int* a = new int[5];
    int* b;
    delete[] a;
    if (b)
    {
        delete[] b;
    }
}
