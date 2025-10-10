#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

class PmergeMe
{
    private:
        std::vector<std::vector<int> > merge;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        std::vector<std::vector<int> > getter();
        void setter(std::vector<std::vector<int> > set);
        PmergeMe &operator=(const PmergeMe &op);
        ~PmergeMe();
};


#endif