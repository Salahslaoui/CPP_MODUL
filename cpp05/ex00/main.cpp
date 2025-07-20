#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b("salah", 1);

    std::cout << b;
    std::cout << b.getName() << std::endl;
    std::cout << b.getGrade() << std::endl;
}