#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

struct Employee
{
    std::string name;
    std::uint64_t ID;
};

// namespace std
// {
//     template <>
//     class hash<Employee>
//     {
//     public:
//         std::uint64_t operator()(const Employee& employee) const
//         {
//              return std::hash<int>{}(employee.ID);
//             //   computes the hash of an employee using a variant
//             //   of the Fowler-Noll-Vo hash function
//              constexpr std::uint64_t prime{0x100000001B3};
//              std::uint64_t result{0xcbf29ce484222325};

//              for (std::uint64_t i{}, ie = employee.name.size(); i != ie; ++i)
//                  result = (result * prime) ^ employee.name[i];

//              return result ^ (employee.ID << 1);
//          }
//     };
// }

// CustomHasher(key) -> value;



struct CustomEqual
{
    bool operator()(const Employee& a, const Employee& b) const
    {
        return true;
    }
};

int main()
{
    Employee employee;
    employee.name = "Zaphod Beeblebrox";
    employee.ID = 42;

    //std::hash<Employee> hash_fn;
    //std::cout << hash_fn(employee) << '\n';
    std::unordered_map<Employee, int, CustomHasher, CustomEqual> map;
    map[employee] = 2;
}


/*

key - hash - value


f(int i ){return i % 10;}

f(1) = 1;
f(11) = 1;

map[1] = "hello";
map[1] = "bye";

hash = f(key)
if (hash already exists)
{
    if (newKey == currentKey)
    {

    }
}
*/