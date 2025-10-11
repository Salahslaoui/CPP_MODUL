#include "PmergeMe.hpp"

int comp;

void    check_av(char *av)
{
    for(size_t i = 0; av[i]; ++i)
    {
        if (av[i] < '0' || av[i] > '9')
            throw std::runtime_error("you must enter only digit!!");
        if (std::atoll(av) > 2147483647 || std::atoll(av) < -2147483648)
            throw std::runtime_error("you have exeed the max int");
    }
}

bool compareFront(const std::vector<int>& a, const std::vector<int>& b)
{
    comp++;
    if (a.empty() && b.empty()) return false;
    if (a.empty()) return false;
    if (b.empty()) return false;
    return a.front() < b.front();
}

int Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

std::vector<size_t> generate(size_t len)
{
    std::vector<size_t> seq;
    size_t i = 2;
    int j;

    while (i < len)
    {
        if ((j = Jacobsthal(i)) >= len)
        {
            seq.push_back(len);
            break;
        }
        else
            seq.push_back(j);
        i++;
    }
    return seq;
}

void fill_save(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &save)
{
    std::vector<size_t> seq = generate(save.size());
    size_t current;
    size_t next;
    size_t pads = 0;
    for (size_t i = 0; i < save.size(); ++i)
    {
        // if (i == 0)
        // {
        //     tmp.push_back(save[i]);
        //     continue;
        // }
        std::vector<std::vector<int> >::iterator pos = std::lower_bound(tmp.begin(), tmp.begin() + pads + i, save[i], compareFront);
        tmp.insert(pos, save[i]);
        pads++;
    };
    for (size_t i = 0; i < tmp.size(); ++i)
    {
        std::cout << "Pairsss " << i + 1 << " " << tmp[i].size() << " " << ": ";
        for (int j = 0; j < tmp[i].size(); ++j)
            std::cout << tmp[i][j] << " ";
        std::cout << "\n";
    }
}

void fill_left(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &save)
{
    for (size_t i = 0; i < save.size(); ++i)
    {
        std::vector<std::vector<int> >::iterator pos = std::lower_bound(tmp.begin(), tmp.end(), save[i], compareFront);
        tmp.insert(pos, save[i]);
    };
}

void    merge_container(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &leftover)
{
    size_t pair_size = 0;
    std::vector<std::vector<int> > save;
    std::vector<int> left;
    std::vector<int> p;

    for (size_t j = 0; j < tmp.size(); ++j)
    {
        if (j + 1 < tmp.size())
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
    }
    if (tmp.size() > 1)
        merge_container(tmp, leftover);
    for (size_t j = 0; j < tmp.size(); ++j)
    {
        pair_size = tmp[j].size() / 2;
        std::vector<int> split(tmp[j].begin() + pair_size, tmp[j].end());
        for (size_t i = 0; i < left.size(); ++i)
            split.push_back(left[i]);
        tmp[j].erase(tmp[j].begin() + pair_size, tmp[j].end());
        save.push_back(split);
    }
    // save.insert(save.end(), left.begin(), left.end());
    // for (size_t i = 0; i < save.size(); ++i)
    // {
    //     std::cout << "Pairsss " << i + 1 << " " << save[i].size() << " " << ": ";
    //     for (int j = 0; j < save[i].size(); ++j)
    //         std::cout << save[i][j] << " ";
    //     std::cout << "\n";
    // }
    fill_save(tmp, save);
    // fill_left(tmp, left);
}

std::vector<std::vector<int> > pair_merge(char **av)
{
    std::vector<std::vector<int> > leftover;
    std::vector<std::vector<int> > tmp;
    std::vector<int> p;
    size_t pair_size = 0;
    size_t save;
    int a;
    int b;

    for (size_t i = 1; av[i]; i += 1) 
    {
        std::vector<int> p;
        check_av(av[i]);
        int a = std::atoi(av[i]);
        p.push_back(a);
        tmp.push_back(p);
        p.erase(p.begin(), p.end());
    }
    save = tmp.size();
    merge_container(tmp, leftover);
    for (size_t i = 0; i < tmp.size(); ++i)
    {
        std::cout << "Pair " << i + 1 << " " << tmp[i].size() << " " << ": ";
        for (int j = 0; j < tmp[i].size(); ++j)
            std::cout << tmp[i][j] << " ";
        std::cout << "\n";
    }
    return tmp;
}


int main(int ac, char **av)
{
    std::vector<std::vector<int> > result;
    PmergeMe Pmer;

    if (ac < 2)
        return (std::cerr << "Must be at least 2 arguments!" << std::endl, 1);
    Pmer.setter(pair_merge(av));
    result = Pmer.getter();
    std::cout << "comparaison number: " << comp << std::endl;
}
