#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream is("/Users/sairamanakiran/workspace/test/testHex");
    if (is)
    {
        std::cout << "opened" << std::endl;
        std::string line;
        while(getline(is, line))
        {
            std::cout << line << std::endl;
            std::istringstream ss(line);
            std::string discard;
            while (getline(ss,discard,","))
            {
                std::cout << discard << " 2nd while" << std::endl;
            }
        }
    
    }
}
