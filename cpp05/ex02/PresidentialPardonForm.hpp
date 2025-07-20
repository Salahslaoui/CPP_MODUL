#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string str);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    void execute(Bureaucrat const & executor) const;
    PresidentialPardonForm operator=(const PresidentialPardonForm &op);
    class Signed : std::exception
    {
        private:
            std::string val;
        public:
            Signed(std::string str);
            const char *what() const throw();
            ~Signed() throw();
    };
    ~PresidentialPardonForm();
};


#endif