#include "Form.hpp"

Form::Form(std::string str, int si, int ex) : name(str), si(false), grade_si(si), grade_ex(ex)
{
    if (si > 150 || ex > 150)
        throw GradeTooLowException("Grade too low!!");
    else if (si < 1 || ex < 1)
        throw GradeTooHighException("Grade too high!!");
}

void Form::beSigned(Bureaucrat br)
{
    if (br.getGrade() > grade_si)
        throw GradeTooLowException("Grade too low!!");
    else
        si = true;
}

bool Form::getSigned()
{
	return si;
}

std::ostream &operator<<(std::ostream &os, Form F)
{
    os << "the name is : " << F.getName() << std::endl;
    os << "the signed grade is : " << F.getGrade_si() << std::endl;
    os << "the execution grade is : " << F.getGrade_ex() << std::endl;
	if (F.getSigned())
		os << "the Form is signed!" << std::endl;
	else
		os << "the Form isn't signed!" << std::endl;
    return os;
}

std::string Form::getName()
{
    return name;
}

int Form::getGrade_ex()
{
    return grade_ex;
}

int Form::getGrade_si()
{
    return grade_si;
}

Form::GradeTooHighException::GradeTooHighException(std::string str) : val(str)
{}

const char *Form::GradeTooHighException::what() const throw()
{
    return val.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string str) : val(str)
{}

const char *Form::GradeTooLowException::what() const throw()
{
    return val.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}


