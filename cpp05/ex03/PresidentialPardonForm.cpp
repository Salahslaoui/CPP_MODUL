#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("target", 25, 5), target("target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string str) : AForm(str, 25, 5), target(str)
{}

PresidentialPardonForm::Signed::Signed(std::string str) : val(str)
{}

const char *PresidentialPardonForm::Signed::what() const throw()
{
    return (val.c_str());
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getSi())
        throw Signed("that form isn't signed!!");
    if (executor.getGrade() > getGrade_ex())
        throw GradeTooLowException("Grade too low!!");
    std::cout << target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
    (*this) = copy;
}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
    if (this != &op)
        (*this).target = op.target;
    return (*this);
}

PresidentialPardonForm::Signed::~Signed() throw()
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}
