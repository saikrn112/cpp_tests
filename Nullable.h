#ifndef NULLABLE_H_
#define NULLABLE_H_

#include <iostream>

template<typename T>
class Nullable
{
    public:
        Nullable()
            : m_isNull(true)
            , m_data()
        {
        }

//        Nullable(T&& data)
//            : m_isNull(false)
//            , m_data(data)
//        {
//        }

        Nullable(T data)
            : m_isNull(false)
            , m_data(data)
        {
        }

        void reset()
        {
            m_isNull = true; 
        }

        const T& get() const
        {
            return m_data;
        }

        void set(T data)
        {
            m_isNull = false;
            this->m_data = data;
        }

        bool isNull() const
        {
            return m_isNull;
        }

        Nullable& operator =(const T& data) 
        {
            set(data);
            return *this;
        }

        Nullable& operator =(const Nullable& from) = default;

        explicit operator bool() const
        {
            return !m_isNull;
        }

        const T& operator *() const
        {
            return m_data;
        }

        T& operator *()
        {
            return m_data;
        }

        const T* operator->() const
        {
            return &m_data;
        }

        T* operator->()
        {
            return &m_data;
        }

        std::ostream& print(std::ostream& os) const
        {
            return (m_isNull ? (os << NULL_BIT) : (os << m_data));
        }

        std::istream& read(std::istream& is)
        {
            if (is.peek() == NULL_BIT) 
            {
                char nullBit;
                is >> nullBit;
                m_isNull = true;
            }
            else
            {
                m_isNull = false;
                is >> m_data;
            }

            return is;
        }
        
        static const char NULL_BIT = 0x02;

    private:
        bool m_isNull;
        T m_data;
};

template<typename T>
inline std::ostream& operator <<(std::ostream& os, const Nullable<T>& obj)
{
    return obj.print(os);
}

template<typename T>
inline std::istream& operator >> (std::istream& is, Nullable<T>& obj)
{
        return obj.read(is);
}

template<typename T>
inline bool operator < (const Nullable<T>& lhs, const Nullable<T>& rhs)
{
    if (!rhs) { return false; }
    
    if (!lhs) { return true; }

    return *lhs < *rhs;
}

template<typename T>
inline bool operator > (const Nullable<T>& lhs, const Nullable<T>& rhs)
{
    return rhs < lhs;
}

template<typename T>
inline bool operator == (const Nullable<T>& lhs, const Nullable<T>& rhs)
{
    return !(lhs < rhs) && !(lhs > rhs);
}

template<typename T>
inline bool operator != (const Nullable<T>& lhs, const Nullable<T>& rhs)
{
    return !(lhs == rhs);
}

#endif /*NULLABLE_H_*/ 
