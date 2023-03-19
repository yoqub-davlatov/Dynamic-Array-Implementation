# Dynamic Array in C++

Basic implementation of std::vector in C++

Class Vector supports the following methods:

1. Vector() - default ctor
2. Vector(int, T) - ctor that allocates memory for number of elements, and fills them with passed argument
3. push_back(cosnt T&)
4. push_back(T&&)
5. emplace_back(Args&& .. args)
6. pop_back()
7. clear()
8. size()
9. capacity()
10. empty()
11. back()
12. operator[](int)
13. const operator[](int) const

The following class supports two kind of iterators for traversing. The following methods are related to them:

14. begin()
15. end()
16. rbegin()
17. rend()

After finishing the scope, destructor is called, and allocated memory gets released
18. ~Vector()

