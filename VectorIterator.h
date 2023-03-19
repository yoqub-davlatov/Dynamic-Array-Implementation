template <typename Vector>
class VectorIterator
{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;

private:
    PointerType m_Ptr;

public:
    VectorIterator(PointerType ptr) : m_Ptr(ptr)
    {
    }

    VectorIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator it = *this;
        ++(*this);
        return it;
    }
    
    VectorIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator it = *this;
        --(*this);
        return it;
    }

    ReferenceType operator[](int index)
    {
        return m_Ptr[index];
    }

    PointerType operator->()
    {
        return *m_Ptr;
    }

    ReferenceType operator*()
    {
        return *m_Ptr;
    }

    bool operator==(const VectorIterator& other)
    {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator& other)
    {
        return m_Ptr != other.m_Ptr;
    }
};