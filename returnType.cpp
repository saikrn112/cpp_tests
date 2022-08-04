#include <iostream>
using namespace std;
struct Clear
{
    int    operator()(int) const;    // The parameter type is
    double operator()(double) const; // equal to the return type.
};

int Clear::operator ()(int a) const
{
    return a + 1;
}
double Clear::operator ()(double a) const
{
    return a + 1.5;
}

struct Confused
{
    double operator()(int) const;     // The parameter type is not
    int    operator()(double) const;  // equal to the return type.
};
double Confused::operator ()(int a) const
{
    return a + 1;
}
int Confused::operator ()(double a) const
{
    return a + 1.5;
}

template <class Obj>
class Calculus
{
public:
    template<class Arg> 
    Arg operator()(Arg& a) const
    {
        return member(a);
    }
private:
    Obj member;
};


int main()
{
    int a = 1;
    double b = 2;
    Calculus<Clear> calcObj1;
    cout << calcObj1(a) << endl;
    cout << calcObj1(b) << endl;
    Calculus<Confused> calcObj2;
    cout << calcObj2(a) << endl;
    cout << calcObj2(b) << endl;
    return 0;
}
