#include <iostream>
#include "Vector.h"
#include "myType.h"

int main()
{
    {
        Vector<std::string> v;
        v.emplace_back("{2 , 3}");
        v.emplace_back("{4 , 4}");
        v.emplace_back("{2 , 1}");
        v.emplace_back("{4 , 2}");
        v.emplace_back("{5 , 0}");
        v.pop_back();
        std::cout << v.capacity() << std::endl;
        for (std::string& s : v)
        {
            std::cout << s << ' ';
        }
        std::cout << std::endl;
        for (auto it = v.rbegin(); it != v.rend(); it++)
        {
            std::cout <<*it << ' ';
        }
        std::cout << std::endl;
        v.pop_back();
        v.pop_back();
    
        std::cout << v.capacity() << std::endl;
        std::cout << v.back() << std::endl;
    }
    std::cout << "Success" << std::endl;
    {
        Vector<myType> v;
        v.emplace_back(2, 3);
        v.emplace_back(4, 4);
        v.emplace_back(0, 1);
        v.emplace_back(4, 2);
        v.emplace_back(5, 0);
        v.pop_back();
        std::cout << v.capacity() << std::endl;
        for (Vector<myType>::iterator it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
        for (auto it = v.rbegin(); it != v.rend(); it++)
        {
            std::cout <<*it << ' ';
        }
        std::cout << std::endl;
        v.pop_back();
        v.pop_back();
    
        std::cout << v.capacity() << std::endl;
        std::cout << v.back() << std::endl;
    }
    std::cout << "Success" << std::endl;
    {
        Vector<int> v;
        v.push_back(2);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(8);
        v.pop_back();
        std::cout << v.capacity() << std::endl;
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;
        for (auto it = v.rbegin(); it != v.rend(); it++)
        {
            std::cout <<*it << ' ';
        }
        std::cout << std::endl;
        v.pop_back();
        v.pop_back();
    
        std::cout << v.capacity() << std::endl;
        std::cout << v.back() << std::endl;
    }
    std::cout << "Success" << std::endl;
}