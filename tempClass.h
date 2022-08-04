#ifndef TEMP_CLASS_H_
#define TEMP_CLASS_H_
#include <iostream>

template <class T>
auto max(T lhs, T rhs)
{
    return (lhs > rhs) ? lhs : rhs;
}

class TestAutoReturn
{
public:

    TestAutoReturn(const double& a, const double& b)
    : m_a (a)
    , m_b (b)
    {
    }

    auto& getA() const
    {
        return m_a;
    }
    auto& getB() const
    {
        return m_b;
    }

    void set(const double& valA = 9.2, const double& valB = 8.4)
    {
        auto& a = getA();
        a = valA;
//        getA() = valA;
//        getB() = valB;
    }

    void print(std::ostream& os = std::cout) const
    {
        os << "A:" << getA() <<  " B:" << getB() << std::endl;
    }
    
private:
//    const double& getA() const
//    {
//        return m_a;
//    }
//    double& getA()
//    {
//        return m_a;
//    }
//    const double& getB() const
//    {
//        return m_b;
//    }
//    double& getB()
//    {
//        return m_b;
//    }

    double m_a;
    double m_b;

};

#endif /* TEMP_CLASS_H_ */
