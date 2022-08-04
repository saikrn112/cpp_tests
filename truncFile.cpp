#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    std::cout << getpagesize() + 1024*1024*1024 + sizeof(uint32_t)<< std::endl;
    std::string path = "/Users/sairamanakiran/tmp";
    //truncate(path.c_str(),1024*1024);
    return 0;
}
