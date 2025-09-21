#include "Span.hpp"

Span::Span(unsigned int N) : n(N)
{}

Span::Span(const Span &copy)
{
    (*this) = copy;
}

Span &Span::operator=(const Span &op)
{
    if (this != &op)
    {
        n = op.n;
        span = op.span;
    }
    return (*this);
}

void    Span::addNumber(int N)
{
    if (span.size() + 1 > n)
        throw std::runtime_error("max size reached!!");
    if (std::find(span.begin(), span.end(), N) != span.end())
        throw std::runtime_error("Duplicate value detected!!");
    span.push_back(N);
}

int Span::shortestSpan()
{
    int tmp = 0;

    if (span.size() < 2)
        throw std::runtime_error("there is less than 2");
    tmp = std::abs(span[0] - span[1]);
    for(size_t i = 0; i < span.size(); ++i)
    {
        for(size_t j = i + 1; j < span.size(); ++j)
        {
            if (tmp > std::abs(span[i] - span[j]))
                tmp = std::abs(span[i] - span[j]);
        }
    }
    return tmp;
}

int Span::longestSpan()
{
    int tmp = 0;

    if (span.size() < 2)
        throw std::runtime_error("there is less than 2");
    tmp = std::abs(span[0] - span[1]);
    for(size_t i = 0; i < span.size(); ++i)
    {
        for(size_t j = i + 1; j < span.size(); ++j)
        {
            if (tmp < std::abs(span[i] - span[j]))
                tmp = std::abs(span[i] - span[j]);
        }
    }
    return tmp;
}

std::vector<int> &Span::get_span()
{
    return span;
}

Span::~Span()
{}
