#include <iostream>
enum class  Type
{
    Int,
    Float
};

class INT
{
public:
    INT()
    {
        std::cout << "INT" << std::endl;
    };
    void print() const
    {
    }
};

class FLOAT
{
public:
    FLOAT()
    {
        std::cout << "FLOAT" << std::endl;
    };
    void print() const
    {
    }

};

template <typename T>
void func1(T t)
{
    std::cout << "func1" << std::endl;
}

void func2()
{
    std::cout << "func2" << std::endl;
}

template <typename T,
            auto t, 
            typename T1 = std::conditional_t<t == Type::Int,INT,FLOAT>>
void func()
{
    T1 a;
    if constexpr (std::is_same_v<decltype(t),Type>)
    {
        if constexpr (t == Type::Int)
        {
           func1(t); 
        }
        else if constexpr (t == Type::Float)
        {
            func2();
        }

    }
    else
    {
        static_assert(true,"fail");
    }

}

