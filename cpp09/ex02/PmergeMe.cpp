#include "PmergeMe.hpp"

size_t PmergeMe::comp = 0;

PmergeMe::PmergeMe() : nb(0)
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    (void) copy;
}

bool PmergeMe::compareFront(const std::deque<int>& a, const std::deque<int>& b)
{
    comp++;
    if (a.empty() && b.empty()) return false;
    if (a.empty()) return false;
    if (b.empty()) return false;
    return a.front() < b.front();
}

int Jacobsthal_1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal_1(n - 1) + 2 * Jacobsthal_1(n - 2);
}

std::deque<size_t> generate_1(size_t len)
{
    std::deque<size_t> seq;
    size_t i = 2;
    size_t current = 0;
    size_t previous = 1;
    size_t j = Jacobsthal_1(i);

    while (j < len)
    {
        current = j;
        seq.push_back(j);
        while (previous < --current)
            seq.push_back(current);
        previous = j;
        i++;
        j = Jacobsthal_1(i);
    }
    if (j  >= len)
        seq.push_back(len);
    for (size_t k = len-1; k > previous; k--)
        seq.push_back(k);
    return seq;
}

void PmergeMe::fill_save(std::deque<std::deque<int> > &tmp, std::deque<std::deque<int> > &save)
{
    std::deque<size_t> seq = generate_1(save.size());
    size_t pads = 1;

    tmp.insert(tmp.begin(), save.begin(), save.begin() + 1);
    if (save.size() > 1)
    {
        for (size_t i = 1; i < seq.size(); ++i)
        {
            std::deque<std::deque<int> >::iterator pos =
                std::lower_bound(tmp.begin(), tmp.begin() + pads + seq[i] - 1, save[seq[i] - 1], compareFront);
            tmp.insert(pos, save[seq[i] - 1]);
            pads++;
        }
    }
}

void PmergeMe::merge_container(std::deque<std::deque<int> > &tmp)
{
    std::deque<std::deque<int> > save;
    std::deque<int> left;
    int hasleft = 0;

    if ((hasleft = tmp.size() % 2))
    {
        left.insert(left.end(), tmp.back().begin(), tmp.back().end());
        tmp.erase(tmp.end() - 1);
    }
    for (size_t j = 0; j < tmp.size(); ++j)
    {
        if (tmp[j].front() > tmp[j + 1].front())
        {
            tmp[j].insert(tmp[j].end(), tmp[j + 1].begin(), tmp[j + 1].end());
            tmp.erase(tmp.begin() + j + 1);
        }
        else
        {
            tmp[j + 1].insert(tmp[j + 1].end(), tmp[j].begin(), tmp[j].end());
            tmp.erase(tmp.begin() + j);
        }
        comp++;
    }
    if (tmp.size() > 1)
        merge_container(tmp);

    size_t pair_size = tmp[0].size() / 2;
    for (size_t j = 0; j < tmp.size(); ++j)
    {
        std::deque<int> split(tmp[j].begin() + pair_size, tmp[j].end());
        tmp[j].erase(tmp[j].begin() + pair_size, tmp[j].end());
        save.push_back(split);
    }
    if (hasleft)
        save.push_back(left);
    fill_save(tmp, save);
}

size_t PmergeMe::setter_nb()
{
    return (nb);
}

std::deque<std::deque<int> > PmergeMe::pair_merge(char **av)
{
    std::deque<std::deque<int> > tmp;
    std::deque<int> p;

    for (size_t i = 1; av[i]; i += 1)
    {
        std::deque<int> p;
        int a = std::atoi(av[i]);
        p.push_back(a);
        tmp.push_back(p);
        p.clear();
    }
    merge_container(tmp);
    nb = comp;
    return tmp;
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