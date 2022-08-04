#include <iostream>
using namespace std;

class Box
{
public:
    Box() = delete;
    Box(int a):m_a(a){};
    ~Box(){};
    void printVar(){cout << m_a << endl;};
private:
    int m_a;
};

int main()
{
    Box box(1);
    Box* boxPtr = new Box[5]; // allocate 2*sizeof(Box) in the heap memory;
    int* intPtr = new int[5]; // allocate 5*sizeof(int) in the heap memory;
    return 0;
}
