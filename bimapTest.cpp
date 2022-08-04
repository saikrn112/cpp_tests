#include <iostream>
#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
// from boost_1_65_1/boost/functional/hash/hash.hpp
inline uint64_t hash_combine_impl(uint64_t h, uint64_t k)
{
    const uint64_t m = 0xc6a4a7935bd1e995;
    const int r = 47;

    k *= m;
    k ^= k >> r;
    k *= m;

    h ^= k;
    h *= m;

    // Completely arbitrary number, to prevent 0's
    // from hashing to 0
    h += 0xe6546b64;
    return h;
}

template<typename L, typename R>
void print(boost::bimap<L,R>& map)
{
    for (auto i = map.left.begin(); i != map.left.end(); ++i) 
    {
        std::cout << i->first << " " << i->second << std::endl;
    }
}

struct AB
{
    int a;
    int b;
    operator size_t() const
    {
        size_t h = std::hash<int>{}(a);
        h = hash_combine_impl(h,std::hash<int>{}(b));
        return h;
    }
};

std::ostream& operator << (std::ostream& os, const AB& ab)
{
    os << ab.a << " " << ab.b << ":";
    return os;
}

bool operator < (const AB& ab1, const AB& ab2)
{
    if (ab1.a < ab2.a)
    {
        return ab1.b < ab2.b;
    }
    return false;
}

struct KeyHash
{
    template<typename T> std::size_t operator()(const T& t) const
    {
        return static_cast<std::size_t>(t);
    }

};

int main()
{
//    typedef boost::bimap<
//            boost::bimaps::unordered_multiset_of<AB,KeyHash,std::equal_to<AB>>,
//            boost::bimaps::unordered_set_of<std::string>
//        > traderTest;
    typedef boost::bimap<
            boost::bimaps::multiset_of<AB,std::less<AB>>,
            boost::bimaps::unordered_set_of<std::string>
        > traderTest;
    typedef traderTest::value_type tR;
    traderTest tt;
    tt.insert(tR({1,1},"hello"));
    tt.insert(tR({1,2},"re"));
    tt.insert(tR({1,3},"re1"));
    tt.insert(tR({2,4},"re2"));
    tt.insert(tR({2,5},"re4"));
    tt.insert(tR({2,6},"re5"));
    tt.insert(tR({3,7},"rw2"));


    std::cout << "*****Just Print" << std::endl;
    print(tt);
    std::cout << "*****Finding 1,1" << std::endl;
    AB ab;
    ab.a = 1;
    ab.b = 1;
    auto foundP = tt.left.equal_range(ab);
    for (auto found = foundP.first; found != foundP.second; ++found)
    {
        std::cout << found->first << " " << found->second << std::endl;
    }
    std::cout << "*****Looping delete" << std::endl;
    auto foundE = tt.left.begin();
    while (foundE != tt.left.end())
    {
        if (foundE->first.a == 2)
        {
            foundE = tt.left.erase(foundE);    
            continue;
        }
        foundE++;
    }
    std::cout << "*****Just Print" << std::endl;
    print(tt);

}
