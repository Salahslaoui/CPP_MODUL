#include "Intern.hpp"

int main()
{
    Intern l;
    AForm *form = l.makeform("shrubbery creation", "slaoui");

    if (form)
    {
        try
        {
            Bureaucrat s("salah", 145);
            form->beSigned(s);
            form->execute(s);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
}