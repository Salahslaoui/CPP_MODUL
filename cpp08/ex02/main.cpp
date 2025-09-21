#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "Testing MutantStack" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "----Iterator----" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "-----Const_Iterator----" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "-----Reverse_Iterator-----" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "-----Reverse_const_iterator-----" << std::endl;
    MutantStack<int>::const_reverse_iterator rcit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator rcite = mstack.rend();
    while (rcit != rcite)
    {
        std::cout << *rcit << std::endl;
        ++rcit;
    }

    std::cout << "Testing std::list (reference)" << std::endl;

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "Back element: " << mlist.back() << std::endl;

    mlist.pop_back();
    std::cout << "Size after pop: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::cout << "----Iterator----" << std::endl;
    std::list<int>::iterator it1 = mlist.begin();
    std::list<int>::iterator ite1 = mlist.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    std::cout << "-----Const_Iterator----" << std::endl;
    std::list<int>::const_iterator cit1 = mlist.begin();
    std::list<int>::const_iterator cite1 = mlist.end();
    while (cit1 != cite1)
    {
        std::cout << *cit1 << std::endl;
        ++cit1;
    }

    std::cout << "-----Reverse_Iterator-----" << std::endl;
    std::list<int>::reverse_iterator rit1 = mlist.rbegin();
    std::list<int>::reverse_iterator rite1 = mlist.rend();
    while (rit1 != rite1)
    {
        std::cout << *rit1 << std::endl;
        ++rit1;
    }

    std::cout << "-----Reverse_const_iterator-----" << std::endl;
    std::list<int>::const_reverse_iterator rcit1 = mlist.rbegin();
    std::list<int>::const_reverse_iterator rcite1 = mlist.rend();
    while (rcit1 != rcite1)
    {
        std::cout << *rcit1 << std::endl;
        ++rcit1;
    }

    return 0;
}