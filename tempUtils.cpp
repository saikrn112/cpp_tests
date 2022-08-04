#include <type_traits>
#include <vector>
#include <iostream>
#define qb_gen_mf_detector(func)                                        \
template <typename T>                                                   \
class qb_has_mf_##func {                                                \
public:                                                                 \
    template <typename U>                                               \
    static std::true_type check(decltype(&U::func));                    \
    template <typename U>                                               \
    static std::false_type check(...);                                  \
                                                                        \
    static const bool value = decltype(check<T>(nullptr))::value;       \
};                                                                      \
template <typename T>                                                   \
using qb_type_has_mf_##func =                                           \
typename std::enable_if<qb_has_mf_##func<T>::value>::type*;             \
template <typename T>                                                   \
using qb_type_doesnt_have_mf_##func =                                   \
typename std::enable_if<!qb_has_mf_##func<T>::value>::type*;

#define qb_type_has_mf(T, func)         qb_type_has_mf_##func<T> = nullptr
#define qb_type_doesnt_have_mf(T, func) qb_type_doesnt_have_mf_##func<T> = nullptr

struct A
{
    void fromProtoBuffer()
    {
        int a = 1;
    }
private:
    void fromProtoBuffer1(std::vector<int>& b)
    {
        int a = 1;
    }
};

qb_gen_mf_detector(toProtoBuffer)
qb_gen_mf_detector(fromProtoBuffer)

template <typename T, qb_type_doesnt_have_mf(T, fromProtoBuffer)>
bool getProtoMsg(T& v)
{
    std::cout << "exists is not enabled" << std::endl;
    return true;
}

template <typename T, qb_type_has_mf(T, fromProtoBuffer)>
bool getProtoMsg(T& v)
{
    std::cout << "exists enabled" << std::endl;
    return true;
}

int main()
{
    A a;
    getProtoMsg(a);
}
