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

AForm   *Intern::makeform(std::string name, std::string target)
{
    AForm* (*ptr[3]) (std::string target) = {&ShrubberyCreationForms, &RobotomyRequestForms, &PresidentialPardonForms};
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3 ; ++i)
    {
        if (name == names[i])
        {
            std::cout << name << " executed " << target << std::endl;
            return ((*ptr[i])(target));
        }
    }
    std::cerr << "this form doesn't exist!!" << std::endl;
    return (NULL);
}

Intern::~Intern()
{}
