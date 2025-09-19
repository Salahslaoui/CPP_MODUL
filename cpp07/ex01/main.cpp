#include "iter.hpp"

template <typename T>
void add(T &a)
{
    a += 1;
    return;
}

template <typename T>
void print(T &a)
{
    std::cout << a << std::endl;
    return;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    iter(a, 5, print<int>);
    iter(a, 5, add<int>);
    iter(a, 5, print<int>);
}