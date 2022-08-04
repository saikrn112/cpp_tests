#include <iostream>
#include <vector>
#include <unordered_map>

bool cmp(const std::pair<int , int>& a, 
        const std::pair<int , int>& b)
{
    return a.second < b.second;
}

int main(int argc, char** argv)
{
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (auto i =0; i < n; i++)
    { 
        std::cin >> arr[i];
    }


    std::unordered_map<int,int> map;

    for (auto i =0; i < n; i++)
    {
        map[arr[i]]++;
    }

    std::sort(map.begin(),map.end(),cmp);
}
