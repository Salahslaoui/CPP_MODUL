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
        AForm(std::string str, int si, int ex);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &op);
        std::string getName() const;
        int getGrade_si();
        int getGrade_ex() const;
        bool getSi() const;
        void beSigned(Bureaucrat br);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
		virtual ~AForm();
};

std::ostream &operator<<(std::ostream &os, AForm &F);

#endif
