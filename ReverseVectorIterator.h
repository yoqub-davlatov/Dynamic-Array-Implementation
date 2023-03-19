template<typename Vector>
class ReverseVectorIterator
{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;

private:
    PointerType m_Ptr;

public:
    ReverseVectorIterator(PointerType ptr) : m_Ptr(ptr)
    {
    }

    ReverseVectorIterator& operator++()
    {
        --m_Ptr;
        return *this;
    }

    ReverseVectorIterator operator++(int)
    {
        ReverseVectorIterator it = *this;
        ++(*this);
        return it;
    }
    
    ReverseVectorIterator& operator--()
    {
        ++m_Ptr;
        return *this;
    }

    ReverseVectorIterator operator--(int)
    {
        ReverseVectorIterator it = *this;
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

    bool operator==(const ReverseVectorIterator& other)
    {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const ReverseVectorIterator& other)
    {
        return m_Ptr != other.m_Ptr;
    }
};