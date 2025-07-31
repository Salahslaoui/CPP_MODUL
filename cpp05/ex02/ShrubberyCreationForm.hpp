#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string str);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        void execute(Bureaucrat const & executor) const;
        class Signed : std::exception
        {
            private:
                std::string val;
            public:
                Signed(std::string str);
                const char *what() const throw();
                ~Signed() throw();
        };
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
        ~ShrubberyCreationForm();
};

#endif