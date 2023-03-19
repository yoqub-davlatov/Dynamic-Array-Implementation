#include "VectorIterator.h"
#include "ReverseVectorIterator.h"
template <typename T>
class Vector
{
private:
    size_t m_Size = 0;
    size_t m_Capacity = 0;
    T *m_Data = nullptr;

private:
    void reallocate(size_t newCapacity)
    {
        // allocating memory without calling constructors
        T *newBlock = (T *)::operator new(sizeof(T) * newCapacity);

        // in case of shrinking
        m_Size = std::min(m_Size, newCapacity);

        // moving old elements to new block
        for (int i = 0; i < m_Size; i++)
        {
            new (&newBlock[i]) T(std::move(m_Data[i]));
        }

        // destructing elements from the old block
        for (int i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }

        // releasing memory without calling destructors
        ::operator delete(m_Data, m_Capacity * sizeof(T));

        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
public:
    using iterator = VectorIterator<Vector<T>>;
    using r_iterator = ReverseVectorIterator<Vector<T>>;
    using ValueType = T;
public:
    Vector()
    {
        reallocate(2);
    }

    Vector(size_t newSize, const T& value)
    {
        size_t newCapacity = 1;
        while(newCapacity <= newSize)
        {
            newCapacity = newCapacity << 1;
        }
        T *newBlock = (T *)::operator new(sizeof(T) * newCapacity);

        for (int i = 0; i < newSize; i++)
        {
            new(&newBlock[i]) T(value);
        }

        m_Capacity = newCapacity;
        m_Data = newBlock;
        m_Size = newSize;
    }

    void push_back(const T &item)
    {
        if (m_Size == m_Capacity)
        {
            reallocate(m_Capacity << 1);
        }
        new (&m_Data[m_Size++]) T(item);
    }

    void push_back(T &&item)
    {
        if (m_Size == m_Capacity)
        {
            reallocate(m_Capacity << 1);
        }
        new (&m_Data[m_Size++]) T(std::move(item));
    }

    template <typename... Args>
    T &emplace_back(Args &&...args)
    {
        if (m_Size == m_Capacity)
        {
            reallocate(m_Capacity << 1);
        }
        new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void pop_back()
    {
        if (m_Size > 0)
        {
            m_Data[m_Size - 1].~T();
            if (m_Size < m_Capacity / 2)
            {
                reallocate(m_Capacity >> 1);
            }
            m_Size--;
        }
    }

    const T &operator[](size_t index) const
    {
        return m_Data[index];
    }

    T &operator[](size_t index)
    {
        return m_Data[index];
    }

    void clear()
    {
        for (int i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    size_t size() const
    {
        return m_Size;
    }

    size_t capacity() const
    {
        return m_Capacity;
    }

    bool empty()
    {
        return m_Size == 0;
    }

    T &back()
    {
        return m_Data[m_Size - 1];
    }

    iterator begin()
    {
        return iterator(m_Data);
    }

    iterator end()
    {
        return iterator(m_Data + m_Size);
    }

    r_iterator rbegin()
    {
        return r_iterator(m_Data + m_Size - 1);
    }

    r_iterator rend()
    {
        return r_iterator(m_Data - 1);
    }

    ~Vector()
    {
        for (int i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        ::operator delete[](m_Data);
    }
};