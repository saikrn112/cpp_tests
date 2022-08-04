#include <iostream>
#include <type_traits>
#include <array>
#include <map>
#include <boost/optional.hpp>
#include <optional>
#include <string>
 
struct A {
    int m;
    char a1[3];
    A& operator = (A&) = delete;
    A(A&) = delete;
    A() = default;
};
 
struct B : A {
    int m1;
};
 
struct C {
    virtual void foo();
};

enum class AB : char
{
    a = 'a',
    b = 'b', 
    c = 'c',
};


struct D 
{
public: 
    D() = default;
private: 
    int m_a; 
};
 
int main()
{
    std::cout << static_cast<std::underlying_type<AB>::type>(AB::a) << std::endl;
    //auto v = AB::a;
    //std::cout << static_cast<char&>(v) << std::endl;
    //std::cout << (unsigned int)AB::a << std::endl;
    std::cout << std::boolalpha;
    //static_assert(std::is_pod<B>::value, "A is not a POD");
    std::cout << "A" << std::is_pod<A>::value << '\n';
    std::cout << "is_trivally A" << std::is_trivially_copyable<A>::value << '\n';
    std::cout << "B" << std::is_pod<B>::value << '\n';
    std::cout << "C" << std::is_pod<C>::value << '\n';
    std::cout << "D" << std::is_pod<D>::value << '\n';
    std::array<int,5> arrayInt;
    std::cout << arrayInt.size() << std::endl;
    std::cout << std::is_pod<std::array<int,5>>::value << '\n';
//    std::cout << std::is_pod<boost::optional<int>>::value << '\n';
//    std::cout << std::is_pod<std::optional<int>>::value << '\n';

    A a1;
    memset((void*)&a1,0,sizeof(A));
    a1.m = 5;
    std::string sa = "S";
    memcpy(a1.a1, sa.c_str(),3);

    A b1;
    memset((void*)&b1,0,sizeof(A));
    //b1 = a1;
    strcpy(a1.a1, std::string("A").c_str());

    std::cout << b1.m << " " << b1.a1 << std::endl;

    //bool a = true;
    //bool b = true;;
    //int c = 0;
    //if ( b && (a = false))
    //if ( (c = 1) )
    //{
    //    std::cout << "print false"  << std::endl; 
    //}
    //std::cout << "a:"  <<  a << std::endl; 
}
