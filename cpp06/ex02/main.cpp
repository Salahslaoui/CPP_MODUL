#include "Base.hpp"

Base *generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Point to A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "Point to B" << std::endl;
        return;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Point to C" << std::endl;
        return;
    }
    std::cout << "no match type" << std::endl;
}

void identify(Base& p)
{
    try
    {
		(void)dynamic_cast<A&>(p);
        std::cout << "Referencing to A" << std::endl;
        return;
    }
    catch (std::exception &)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Referencing to B" << std::endl;
        return;
    }
    catch (std::exception &)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Referencing to C" << std::endl;
        return;
    }
    catch (std::exception &)
    {}
}

int main()
{
    std::srand(std::time(NULL));
    Base *p = generate();
    identify(p);
    identify(*p);
	delete p;
}
