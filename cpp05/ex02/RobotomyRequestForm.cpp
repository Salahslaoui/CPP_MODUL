#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string str) : AForm("RobotomyRequestForm", 72, 45), target(str)
{}

RobotomyRequestForm::Signed::Signed(std::string str) : val(str)
{}

const char *RobotomyRequestForm::Signed::what() const throw()
{
    return (val.c_str());
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getSi())
        throw Signed("that form isn't signed!!");
    if (executor.getGrade() > getGrade_ex())
        throw GradeTooLowException("Grade too low!!");
    std::cout << "making some drilling noises!" << std::endl;
	static int counter = 0;
    srand(time(0) + counter++);
    if (rand() % 2 == 0)
        std::cout << target << "has been robotomized" << std::endl;
    else
        std::cout << target << "the robotomy has failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    (*this) = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
    if (this != &op)
        (*this).target = op.target;
    return (*this);
}

RobotomyRequestForm::Signed::~Signed() throw()
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}
