#include <boost/variant.hpp>
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

template <typename T, int size>
constexpr int arrLength(T(&)[size]){return size;}

void func(std::istringstream& is)
{
    std::cout << is.str() << std::endl;
}

struct Error
{
    Error() = delete;
    Error(std::string& error)
    : m_error(error)
    {}
    std::string error;
}

int main()
{
    boost::variant<int, std::string> v;
    std::cout << boost::get<int>(v) << std::endl;

    constexpr int vec[] = {1,2};
    constexpr int size = (std::array<int,arrLength(vec)>{1,2}).size();
    boost::dynamic_bitset<> bt {15, 0};
    std::cout << bt << std::endl;

    func("hello" << " World");
}
