#include <iostream>

int main()
{
    switch(2)
    {
    case 2:
    {
        std::cout << "inside case 2" << std::endl;
        for (;1;)
        {
            std::cout << "inside for" << std::endl;
            for (;1;)
            {
                std::cout << "inside for 2" << std::endl;
                break;
            }
            std::cout << "inside for end" << std::endl;
            break;
        }
        std::cout << "inside case 2 end" << std::endl;
        break;
    }
    default:
    {
        std::cout << "default" << std::endl;
        break;
    }
    }
    std::cout << "ending" << std::endl;
    return 0;
}
