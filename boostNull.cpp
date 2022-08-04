#include <boost/optional/optional.hpp>
#include <iostream>


int main()
{
    boost::optional<bool> asd(false,0);// = boost::make_optional(false);

    if (asd)
    {
        std::cout << "make_optional " << *asd << std::endl;
    }
    boost::optional<bool> asd1;// = boost::make_optional(false);
    if (asd1)
    {
        std::cout << "no make_optional " << *asd1 << std::endl;
    }
}
