#include "Intern.hpp"

Intern::Intern()
{}

AForm *ShrubberyCreationForms(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *RobotomyRequestForms(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *PresidentialPardonForms(std::string target)
{
    return (new PresidentialPardonForm(target));
}

const char *Intern::Error::what() const throw()
{
	return ("this form doesn't exist!!");
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    AForm* (*ptr[3]) (std::string target) = {&ShrubberyCreationForms, &RobotomyRequestForms, &PresidentialPardonForms};
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3 ; ++i)
    {
        if (name == names[i])
        {
            std::cout << "intern" << " created " << name << std::endl;
            return ((*ptr[i])(target));
        }
    }
    throw Error();
}

Intern::~Intern()
{}
