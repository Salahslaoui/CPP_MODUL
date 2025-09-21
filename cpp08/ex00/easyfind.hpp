#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
int easyfind(T a, int b)
{
    for(size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] == b)
            return i;

    }
    throw std::runtime_error("no occurence found!!");
}


#endif