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
    size_t current = 0;
    size_t previous = 1;
    size_t j = Jacobsthal(i);

    while (j < len)
    {
        current = j;
        seq.push_back(j);
        while (previous < --current)
            seq.push_back(current);
        previous = j;
        i++;
        j = Jacobsthal(i);
    }
    if (j  >= len)
        seq.push_back(len);
    for (size_t k = len-1; k > previous; k--)
        seq.push_back(k);
    return seq;
}

void fill_save(std::vector<std::vector<int> > &tmp, std::vector<std::vector<int> > &save)
{
    std::vector<size_t> seq = generate(save.size());
    size_t pads = 1;

    tmp.insert(tmp.begin(), save.begin(), save.begin() + 1);
    if (save.size() > 1)
    {
        for (size_t i = 1; i < seq.size(); ++i)
        {
            std::vector<std::vector<int> >::iterator pos = std::lower_bound(tmp.begin(), tmp.begin() + pads + seq[i] - 1, save[seq[i] - 1], compareFront);
            tmp.insert(pos, save[seq[i] - 1]);
            pads++;
        }
    }
}

void    merge_container(std::vector<std::vector<int> > &tmp)
{
    std::vector<std::vector<int> > save;
    std::vector<int> left;
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
        std::vector<int> split(tmp[j].begin() + pair_size, tmp[j].end());
        tmp[j].erase(tmp[j].begin() + pair_size, tmp[j].end());
        save.push_back(split);
    }
    if (hasleft)
        save.push_back(left);
    fill_save(tmp, save);
}

std::vector<std::vector<int> > pair_merge(char **av)
{
    std::vector<std::vector<int> > tmp;
    std::vector<int> p;

    for (size_t i = 1; av[i]; i += 1) 
    {
        std::vector<int> p;
        check_av(av[i]);
        int a = std::atoi(av[i]);
        p.push_back(a);
        tmp.push_back(p);
        p.erase(p.begin(), p.end());
    }
    merge_container(tmp);
	std::cout << "After: ";
    return tmp;
}


int main(int ac, char **av)
{
    std::vector<std::vector<int> > result;
    std::deque<std::deque<int> > list;
    PmergeMe Pmer;
    std::vector<size_t> seq;
	clock_t times[4];
	try
	{
		if (ac < 2)
			return (std::cerr << "Must be at least 2 arguments!" << std::endl, 1);
		std::cout << "Before ";
		for (size_t i = 1; av[i]; ++i)
			std::cout << av[i] << " ";
		std::cout << std::endl;
		times[0] = clock();
		Pmer.setter(pair_merge(av));
		times[1] = clock();
		for (size_t i = 0; i < Pmer.getter().size(); ++i)
		{
			for (size_t j = 0; j < Pmer.getter()[i].size(); ++j)
				std::cout << Pmer.getter()[i][j] << " ";
		}
		std::cout << std::endl;
		result = Pmer.getter();
		times[2] = clock();
		list = Pmer.pair_merge(av);
		times[3] = clock();
		std::cout << "Time to process a range of " << ac - 1 << "  elements with std::[vector] : " << (double) ((times[1] - times[0])) / CLOCKS_PER_SEC * 1e6 << "us \n";
		std::cout << "Time to process a range of " << ac - 1 << "  elements with std::[deque] : " << (double) ((times[3] - times[2])) / CLOCKS_PER_SEC * 1e6 << "us \n";
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << std::endl;
	}
}
