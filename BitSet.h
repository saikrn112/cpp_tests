#include <vector>

class BitSet
{
private:
    std::vector<bool> m_data;
    size_t m_counter;
public:
    BitSet(const size_t& size, bool flag)
    : m_data(size, flag)
    , m_counter(0)
    {
    }
    size_t count() const
    {
        return m_counter;
    }
    bool none() const
    {
        return m_counter == 0;
    }
    bool test(const size_t& index) const
    {
        return (m_data[index] == true);
    }
    void set(const size_t& index)
    {
        m_data[index] = true;
        m_counter++;
    }
    void reset()
    {
        m_counter = 0;
        std::fill(m_data.begin(), m_data.end(), false);
    }
};