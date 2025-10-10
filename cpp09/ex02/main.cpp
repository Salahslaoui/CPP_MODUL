#include "PmergeMe.hpp"

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
    return a.front() < b.front();
}

size_t fill_save(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &save, size_t pad)
{
    int j = 0;
    size_t pads = 0;
    for (size_t i = 0; i < save.size();)
    {
        j+= pads;
        std::vector<std::vector<int> >::iterator pos = std::lower_bound(tmp.begin(), tmp.begin() + pads, save[i], compareFront);
        tmp.insert(pos, save[i]);
        pads++;
        save.erase(save.begin() + i);
        j++;
    }
    return pad;
}

void    merge_container(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &leftover)
{
    size_t pair_size = 0;
    std::vector<std::vector<int> > save;
    size_t pad = 0;
    // std::vector<int> split;

    // for (size_t i = 1; i <tmp.size(); ++i)
    // {
    //     if (tmp[i].size() != tmp[i - 1].size())
    //     {
    //         leftover.push_back(tmp.back());
    //         tmp.pop_back();   
    //     }
    // }
    // if (tmp.size() % 2 != 0) 
    // {
    //     leftover.push_back(tmp.back());
    //     tmp.pop_back();
    // }
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
        }
    }
    if (tmp.size() > 1)
        merge_container(tmp, leftover);
    for (size_t j = 0; j < tmp.size(); ++j)
    {
        pair_size = tmp[j].size() / 2;
        std::vector<int> split(tmp[j].begin() + pair_size, tmp[j].end());
        tmp[j].erase(tmp[j].begin() + pair_size, tmp[j].end());
        save.push_back(split);
    }
    pad = fill_save(tmp, save, pad);
    for (size_t j = 0; j < tmp.size(); ++j)
    {
        if (tmp[j].size() == 2)
        {
            pair_size = 1;
            std::vector<int> split(tmp[j].begin() + pair_size, tmp[j].end());
            tmp[j].erase(tmp[j].begin() + pair_size, tmp[j].end());
            save.push_back(split);
        }
    }
    pad = fill_save(tmp, save, pad);
}

// void    split_insert(std::vector<std::vector<int> > &tmp, size_t save)
// {
//     for (size_t i = 0; i < save; ++i)
//     {

//     }
// }

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
        check_av(av[i]);
        int a = std::atoi(av[i]);

        std::vector<int> p;

        if (av[i + 1])
        {
            check_av(av[i + 1]);
            int b = std::atoi(av[i + 1]);
            if (a > b)
                p.push_back(a), p.push_back(b);
            else
                p.push_back(b), p.push_back(a);
            i++;
        }
        else 
            p.push_back(a);
        tmp.push_back(p);
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
}
