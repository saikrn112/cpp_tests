#include <iostream>

class TestObj
{
public: 

    TestObj()
    : m_a(100)
    , m_b(101)
    {
    }
    void incr()
    {
        m_a++;
        m_b++;
    }

    std::ostream& print(std::ostream& os) const
    {
        return os << m_a << " " << m_b << " ";
    }

    void update(int a, int b)
    {
        m_a += a;
        m_b += b;
    }

private:
    int m_a; 
    int m_b;
};


std::ostream& operator<<(std::ostream& os, const TestObj obj)
{
    return obj.print(os);
}

void func(int* const a)
{

    *a += 1; // cannot happen
    int *b = new int[2];
    //a = b; // can happen
}

int main(int argc, char** argv)
{
    TestObj obj;


    const TestObj& objRef = obj;
    
    std::cout << "Original:  " << obj << std::endl;
    std::cout << "Reference: " << objRef <<  std::endl;

    obj.incr();
    std::cout << "Original:  " << obj << std::endl;
    std::cout << "Reference: " << objRef <<  std::endl;


    obj.update(1, 2);
    std::cout << "Original:  " << obj << std::endl;
    std::cout << "Reference: " << objRef <<  std::endl;

    
}
