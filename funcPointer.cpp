#include <function>
#include <iostream>

using Closure = std::function<bool(int,int)>;
typedef std::function<bool(int,int)> Closure1;

bool add(int a, int b)
{
    return (a+b>a*b) ? true : false;
}

int main()
{

}
