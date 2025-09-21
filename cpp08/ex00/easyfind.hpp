#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::runtime_error("no occurrence found!!");
    return std::distance(a.begin(), it);
}


#endif