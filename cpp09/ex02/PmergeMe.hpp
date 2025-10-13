#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<std::vector<int> > merge;
        std::vector<std::deque<int> > list;
        static size_t comp;
        size_t nb;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        static bool compareFront(const std::deque<int>& a, const std::deque<int>& b);
        void fill_save(std::deque<std::deque<int> > &tmp, std::deque<std::deque<int> > &save);
        void merge_container(std::deque<std::deque<int> > &tmp);
        std::deque<std::deque<int> > pair_merge(char **av);
        std::vector<std::vector<int> > getter();
        void setter(std::vector<std::vector<int> > set);
        size_t setter_nb();
        PmergeMe &operator=(const PmergeMe &op);
        ~PmergeMe();
};


#endif