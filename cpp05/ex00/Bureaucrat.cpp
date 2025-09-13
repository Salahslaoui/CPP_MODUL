#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Name")
{
    grade = 150;
}

int Bureaucrat::getGrade()
{
    return (grade);
}

std::string Bureaucrat::getName()
{
    return (name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
    this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op)
{
    if (this != &op)
        (*this) = op;
    return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& str) : val(str)
{}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return val.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& str) : val(str)
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return val.c_str();
}

void Bureaucrat::incr()
{
    if (grade - 1 < 1)
            throw GradeTooHighException("Grade too high !!");
    grade -= 1;
}

void Bureaucrat::decr()
{
    if (grade + 1 > 150)
        throw GradeTooLowException("Grade too low !!");
    grade += 1;
}

std::ostream &operator<<(std::ostream& os, Bureaucrat& bu)
{
    os << bu.getName() << ", bureaucrat grade " << bu.getGrade() << "." << std::endl;
    return os;
}

Bureaucrat::Bureaucrat(std::string str, int i) : name(str)
{
    if (i < 1)
        throw GradeTooHighException("Grade too high !!");
    else if (i > 150)
        throw GradeTooLowException("Grade too low !!");
    grade = i;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::~Bureaucrat()
{}
