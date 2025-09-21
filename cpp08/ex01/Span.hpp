#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int n;
        std::vector<int> span;
        Span();
        Span &operator=(const Span &op);
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        std::vector<int> &get_span();
        void    addNumber(int N);
        int shortestSpan();
        int longestSpan();
        template <typename T>
        void addRange(typename T::iterator first,typename T::iterator last)
        {
            int len = std::distance(first, last);
            if (span.size() + len > n)
                throw std::runtime_error("you have exeed the maximum range!!");
            span.insert(span.end(), first, last);
        }
        ~Span();
};


#endif