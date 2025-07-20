#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("ss", 5);
    ShrubberyCreationForm a("ahyaaa");
    RobotomyRequestForm c("oooo");
    PresidentialPardonForm d("salama");
    try
    {
        b.signForm(d);
        d.execute(b);
    }
    catch(ShrubberyCreationForm::Signed &e)
    {
        std::cout << "Signed instance " << e.what() << std::endl;
    }
    catch(RobotomyRequestForm::Signed &e)
    {
        std::cout << "Signed instance " << e.what() << std::endl;
    }
    catch(ShrubberyCreationForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}