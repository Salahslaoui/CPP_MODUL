#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class AForm
{
    private:
        const std::string name;
        bool si;
        const int grade_si;
        const int grade_ex;
    public:
        AForm();
        AForm(std::string str, int si, int ex);
        std::string getName();
        int getGrade_si();
        int getGrade_ex() const;
        bool getSi() const;
        void beSigned(Bureaucrat br);
        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : std::exception
        {
            private:
                std::string val;
            public:
                GradeTooHighException(std::string str);
                const char *what() const throw();
                ~GradeTooHighException() throw();
        };
        class GradeTooLowException : std::exception
        {
            private:
                std::string val;
            public:
                GradeTooLowException(std::string str);
                const char *what() const throw();
                ~GradeTooLowException() throw();
        };
};

std::ostream &operator<<(std::ostream &os, AForm F);

#endif
