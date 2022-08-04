#include <utility>
#include <iostream>

struct A
{
    int a;
};

//template < typename = typename std::enable_if<std::is_same<T,int>::value,T>::type >
//T foo() 
//{
//    return 10;
//}
//
//struct T {
//    enum { int_t, float_t } type;
//    template <typename Integer,
//              std::enable_if_t<std::is_integral<Integer>::value, int> = 0
//    >
//    T(Integer) : type(int_t) {}
// 
//    template <typename Floating,
//              std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0
//    >
//    T(Floating) : type(float_t) {} // OK
//};


template <typename T>
class templ
{
public:
    template<typename N = T, typename std::enable_if<!std::is_floating_point<N>::value,N>::type = 0>
    void foo(){ std::cout << "This is first overload" << std::endl;};

    //template<typename N = T, typename std::enable_if<std::is_floating_point<N>::value,T>::type>
    template<typename N = T, typename std::enable_if<std::is_same<N,float>::value,N>::type = 0>
    void foo(){ std::cout << "This is second overload" << std::endl;};

};

int main() 
{
    templ<float> a;
    a.foo();
}
