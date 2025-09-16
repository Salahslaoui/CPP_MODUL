#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &op);
        AForm   *makeForm(std::string name, std::string target);
		class Error : public std::exception
		{
			const char *what() const throw();
		};
        ~Intern();
};


#endif
