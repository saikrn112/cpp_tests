#include <iostream>
#include <type_traits>
#include <array>
#include <algorithm>
#include "Nullable.h"

struct testArrayStruct
{
    double arr5; // 8bytes
    int arr1; //4bytes
    int arr2; //4bytes
    float arr3; // 4bytes
    void clear();
};

// 4 + 4 + 4 + 8 == 20
// 1 + 1 + 1 ..
// uint16_t size = 20 ;
// 2 bytes + msgInBytes
// char* c = (char*) &str;
// write(size,(void*)c)
testArrayStruct str;

// deduce 2 bytes -- length of msg
// deduce another 2 bytes -- msg_type -- 

std::ostream& operator << (std::ostream&  os, const testArrayStruct& obj)
{
    os  << "TestArrayStruct:  " << obj.arr1 << " " << obj.arr2 << " " << obj.arr3 << " " << obj.arr5;
    return os;
}

void testArrayStruct::clear()
{
    arr1 = 0;
    arr2 = 0;
    arr3 = 0.0;
    arr5 = 0.0;
}

struct base
{
    int a;
    int b;
    int c;
    std::array<testArrayStruct,2> testArray;
    Nullable<double> nullableA;
    base& operator = (const base& ) = default;
    void clear()
    {
        a = 0;
        b = 0;
        c = 0;
        testArrayStruct ab;
        ab.clear();
        //testArray.fill(ab);
        std::fill(testArray.begin(),testArray.begin()+1,ab);
        nullableA = 0;
    }
};

std::ostream& operator << (std::ostream& os, const base& obj)
{
    os << "Base Struct: " << obj.a << " " << obj.b << " " << obj.c;
    for(const auto& iter : obj.testArray)
        os << " arr[" << iter << "]"; 
    os << " " <<  obj.nullableA;
    os << std::endl;
    return os;
}
void print(const base& obj)
{
    std::cout << obj;
}


void put(base& obj)
{
    obj.a = -10;
    obj.b = -1;
    obj.c = -20;
    testArrayStruct ab;
    ab.arr1 = 1;
    ab.arr2 = 2;
    ab.arr3 = 3.5;
    ab.arr5 = 98.5;
    //obj.testArray.fill(ab);
    std::fill(obj.testArray.begin(),obj.testArray.begin()+1,ab);
    obj.nullableA = 1920;
}

struct derived : base
{
    int a1 = 10;
    int b = 20;
    derived& operator = (const derived& ) = default;
    void clear()
    {
        static_cast<base&>(*this).clear();
        a1 = 0;
        b = 0;
    }
};

void put(derived& obj) 
{
    put(static_cast<base&>(obj));
    obj.a1 = -100;
    obj.b = -200;
}

std::ostream& operator << (std::ostream& os, const derived& obj)
{
    os << static_cast<base>(obj)
       << "Derived Struct: " << obj.a << " " << obj.b;
    os << std::endl;
    return os;
}

void print(const derived& obj)
{
    std::cout << obj;
}

void printchar(const char& obj)
{
    const derived& obj1 = reinterpret_cast<const derived&>(obj);
    print(obj1);
}

void fillCharArray()
{
    std::string bufstr = "Hello this is a localstring";
    uint16_t size = sizeof(uint16_t) + bufstr.size() + 1;
    char* buf;

    std::cout << size << " " << strlen(buf) << std::endl;
    memcpy(buf,(void*)(&size),sizeof(uint16_t));

    std::cout << *reinterpret_cast<uint16_t*>(buf)<< std::endl;

    memcpy(buf + sizeof(uint16_t), (void*)bufstr.c_str(), bufstr.size());
    std::cout << size << " " << strlen(buf) << std::endl;

    buf[size-1] = '\0';
    std::cout << size << " " << strlen(buf) << std::endl;
    std::cout << std::string(buf,size) << std::endl;
}

int main(int argc, char** argv)
{
    derived a;
    put(a);
    derived b = a;
    print(a);
    std::cout << '\n' <<  "Printing after converting to mem" << std::endl;
    printchar(reinterpret_cast<const char&>(a));
    std::cout << "Size Of Derived Struct[" << sizeof(derived) << "]" << std::endl;

    a.clear();
    std::cout << '\n' <<  "Printing after clearing" << std::endl;
    print(a);
    printchar(reinterpret_cast<const char&>(a));

    std::cout << b << std::endl;

    //std::cout << std::boolalpha <<  std::is_pod<base>::value << std::endl;
    //fillCharArray();
}

