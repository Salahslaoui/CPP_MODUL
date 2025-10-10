#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    (void) copy;
}

std::vector<std::vector<int> > PmergeMe::getter()
{
    return merge;
}

void PmergeMe::setter(std::vector<std::vector<int> > set)
{
    merge = set;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &op)
{
    if (this != &op)
        merge = op.merge;
    return *this;
}

PmergeMe::~PmergeMe()
{}