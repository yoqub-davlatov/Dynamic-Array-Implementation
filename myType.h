#include <iostream>

struct myType
{
    int a, b;
    int *problem = nullptr;
    myType() : a(0), b(0)
    {
        // std::cout << "default ctor" << std::endl;
        problem = new int[2];
    }

    myType(int a, int b) : a(a), b(b)
    {
        problem = new int[2];
        // std::cout << "ctor" << std::endl;
    }

    myType(const myType &other) = delete;

    myType(myType &&other)
    {
        a = other.a;
        b = other.b;
        other.a = 0;
        other.b = 0;
        problem = other.problem;
        other.problem = nullptr;
        // std::cout << "Move ctor" << std::endl;
    }

    myType &operator=(const myType &other)
    {
        if (&other != this)
        {
            a = other.a;
            b = other.b;
            // std::cout << "Copy assignment" << std::endl;
            for (int i = 0; i < 2; i++)
            {
                problem[i] = other.problem[i];
            }
        }
        return *this;
    }

    myType &operator=(myType &&other)
    {
        a = other.a;
        b = other.b;
        other.a = 0;
        other.b = 0;
        delete[] problem;
        problem = other.problem;
        other.problem = nullptr;
        // std::cout << "Move assignment" << std::endl;
        return *this;
    }

    ~myType()
    {
        delete[] problem;
        // std::cout << "Destructor" << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const myType &item)
    {
        out << item.a << ' ' << item.b;
        return out;
    }
};