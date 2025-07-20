#include "Form.hpp"

int main()
{
    Bureaucrat a("slaoui", 4);
    Form b("document", 151, 3);
    
    try
    {
        a.signForm(b);
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << a.getName() << " Bureaucrat couldn't sign " << b.getName() << " because " << e.what() << std::endl;
    }
}