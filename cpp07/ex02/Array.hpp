#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *arr;
        size_t len;
    public:
        Array(): arr(NULL), len(0)
        {};
        Array(unsigned int n)
        {
            arr = new T[n];
            len = n;
        }
        Array(const Array &copy) : arr(new T[copy.len]), len(copy.len)
        {
            for (unsigned int i = 0; i < len; ++i)
                arr[i] = copy.arr[i];
        }
        Array &operator=(const Array &op)
        {
            if (this != &op)
            {
                delete[] arr;
                len = op.len;
                arr = new T[len];
                for (unsigned int i = 0; i < len; ++i)
                    arr[i] = op.arr[i];
            }
            return *this;
        }
        T& operator[](unsigned int i)
        {
            if (i >= len)
                throw std::out_of_range(" index is out of bounds");
            return arr[i];
        }
        unsigned int size() const
        {
            return len;
        }
        ~Array()
        {
            delete[] arr;
        }
};


#endif
