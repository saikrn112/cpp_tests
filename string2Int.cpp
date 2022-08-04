#include <iostream>
#include <string>
#include <sstream>
inline std::string nextVal(const std::string& str, int index, int val)
{
    if (index > str.length()
        || index < 0 )
    {
        return str;
    }

    int ret = 0;
    std::stringstream ss(str[index]);
    ss >> ret;
    std::stringstream ss1;
    std::cout << "string: " << str 
                << " stringInd: " << str[index]
                << " ret: " << ret << std::endl;
    ret += val;
    ss1 << ret;

    char c = '\0';
    ss1 >> c;
    std::string retString = str;
    retString[index] = c;
    return retString;
}

int main()
{
    std::string a = "10";
    std::cout << nextVal(a,1,2) << std::endl;
    return 0;
}
