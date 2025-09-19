#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename E, typename fun>
void iter(T* arr, E len, fun f)
{
    for(int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}


#endif
