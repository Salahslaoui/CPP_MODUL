#include "AForm.hpp"

AForm::AForm(std::string str, int si, int ex) : name(str), si(false), grade_si(si), grade_ex(ex)
{
    if (si > 150 || ex > 150)
        throw GradeTooLowException("Grade too low!!");
    else if (si < 1 || ex < 1)
        throw GradeTooHighException("Grade too high!!");
}

bool AForm::getSi() const
{
    return si;
}

void AForm::beSigned(Bureaucrat br)
{
    if (br.getGrade() > grade_si)
        throw GradeTooLowException("Grade too low!!");
    else
        si = true;
}

std::ostream &operator<<(std::ostream &os, AForm &F)
{
    os << "the name is : " << F.getName() << std::endl;
    os << "the signed grade is : " << F.getGrade_si() << std::endl;
    os << "the execution grade is : " << F.getGrade_ex() << std::endl;
    return os;
}

std::string AForm::getName() const
{
    return name;
}

int AForm::getGrade_ex() const
{
    return grade_ex;
}

int AForm::getGrade_si()
{
    return grade_si;
}

AForm::GradeTooHighException::GradeTooHighException(std::string str) : val(str)
{}

const char *AForm::GradeTooHighException::what() const throw()
{
    return val.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string str) : val(str)
{}

const char *AForm::GradeTooLowException::what() const throw()
{
    return val.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

AForm::~AForm()
{}
