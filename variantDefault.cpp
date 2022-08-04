#include <variant>
#include <iostream>
struct Error
{
    Error() = delete;
    Error(std::string& error)
    : m_error(error)
    {}
    std::string m_error;
};

    void* operator std::new(size_t size)
    {
        std::cout << size << std::endl;
        std::cout << "I am here" << std::endl;
        return malloc(size);
    }

int main()
{
    std::variant<int,Error> data;
    std::string data1("Nicholas");
}
