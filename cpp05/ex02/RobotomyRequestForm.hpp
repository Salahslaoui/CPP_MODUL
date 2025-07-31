#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string str);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        void execute(Bureaucrat const & executor) const;
        class Signed : std::exception
        {
            private:
                std::string val;
            public:
                Signed(std::string str);
                const char *what() const throw();
                ~Signed() throw();
        };
        RobotomyRequestForm &operator=(const RobotomyRequestForm &op);
        ~RobotomyRequestForm();
};


#endif
