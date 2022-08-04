#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1,2,3,4, 5, 5, 2, 3};
    std::set<int> s;
    std::copy(v.begin(), v.end(), std::inserter(s, s.begin()));

    auto print = [](const int& n){ std::cout << " " << n; };
    std::for_each(s.begin(), s.end(), print);
    std::cout << std::endl;
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;
}
