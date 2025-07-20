#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

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
        void signForm(AForm &sign);
        class GradeTooLowException : std::exception
        {
            private:
            std::string val;
            public:
            GradeTooLowException(const std::string& str);
            const char *what() const throw();
            ~GradeTooLowException() throw() {};
        };
        class GradeTooHighException : std::exception
        {
            private:
            std::string val;
            public:
            GradeTooHighException(const std::string& str);
            const char *what() const throw();
            ~GradeTooHighException() throw();
        };
        std::string getName();
        int getGrade() const;
};

std::ostream &operator<<(std::ostream& os, Bureaucrat& bu);

#endif
