#include <iostream>
#include <string>

std::string traderID(const std::string& s)
{
    auto found = s.find("__",0);
    if (found == std::string::npos)
    {
        return s;
    }

    return s.substr(found+2,std::string::npos);

}

int main()
{
    auto s = "CS__12345";
    auto s1 = "123456";
    auto s2 = "__123456";
    std::cout << traderID(s2) << std::endl;
}
