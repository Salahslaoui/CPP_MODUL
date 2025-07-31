#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
// #include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
    const std::string name;
    int grade;
    public:
    Bureaucrat();
    Bureaucrat(std::string str, int i);
    ~Bureaucrat();
    void incr();
    void decr();
    void signForm(Form &sign);
    class GradeTooLowException : public std::exception
    {
        private:
        std::string val;
        public:
        GradeTooLowException(const std::string& str);
        const char *what() const throw();
        ~GradeTooLowException() throw() {};
    };
    class GradeTooHighException : public std::exception
    {
        private:
        std::string val;
        public:
        GradeTooHighException(const std::string& str);
        const char *what() const throw();
        ~GradeTooHighException() throw();
    };
    std::string getName();
    int getGrade();
};

std::ostream &operator<<(std::ostream& os, Bureaucrat& bu);

#endif
