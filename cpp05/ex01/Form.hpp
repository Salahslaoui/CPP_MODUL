#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form
{
    private:
        const std::string name;
        bool si;
        const int grade_si;
        const int grade_ex;
    public:
        Form();
        Form(std::string str, int si, int ex);
        std::string getName();
        int getGrade_si();
        int getGrade_ex();
        void beSigned(Bureaucrat br);
        class GradeTooHighException : public std::exception
        {
            private:
                std::string val;
            public:
                GradeTooHighException(std::string str);
                const char *what() const throw();
                ~GradeTooHighException() throw();
        };
        class GradeTooLowException : public std::exception
        {
            private:
                std::string val;
            public:
                GradeTooLowException(std::string str);
                const char *what() const throw();
                ~GradeTooLowException() throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form F);

#endif
