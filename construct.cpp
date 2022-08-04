#include <iostream>
using namespace std;

class AC
{
private:
    int m_a1;    
    int m_b1;
public:
    AC(int,int);
    ~AC();
    int m_abinherit1;
};

AC::AC(int a, int b):
    m_a1(a),
    m_b1(b)
{
    cout << "Constructor is called" << endl;
    m_abinherit1 = a + 2*b; // 5;
}

AC::~AC()
{
    cout << "Destructor is called" << endl;
}

class AB
{
private:
    int m_a1;    
    int m_b1;
public:
    AB(int,int);
    ~AB();
    int* dataOnHeap;
    int m_abinherit1;
    bool init(int,int);
};

AB::AB(int a, int b):
    m_a1(a),
    m_b1(b),
    dataOnHeap(nullptr)
{
    cout << "Constructor is called" << endl;
    m_abinherit1 = a + b; // 3;
}
AB::~AB()
{
    cout << "Destructor is called" << endl;
    if(dataOnHeap != nullptr)
    {
        delete dataOnHeap;
    }
}

bool AB::init(int a,int b)
{
    m_a1 = a;
    m_b1 = b;
    return true;
}

class ABinherit : public AB, public AC
{
public:
    ABinherit(int,int);
    ~ABinherit(){};
    int m_abinherit1;
    int m_abinherit2;
    void compute();
};

ABinherit::ABinherit(int a,int b):
    AB(a,b), // Initializer list will initialize base classes
    AC(a,b), // Initializer list will initialize base classes
    m_abinherit1(a), // 1;
    m_abinherit2(b) // 2;
{
};

void ABinherit::compute()
{
    cout << AB::m_abinherit1 + AC::m_abinherit1 << endl;
}

int main()
{

    ABinherit abinherit(1,2);
    abinherit.compute();
    
    return 0;
}
