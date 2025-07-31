#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string str) : AForm("ShrubberyCreationForm", 145, 137), target(str)
{}

ShrubberyCreationForm::Signed::Signed(std::string str) : val(str)
{}

const char *ShrubberyCreationForm::Signed::what() const throw()
{
    return (val.c_str());
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream outfile;
    std::string str;
    if (!getSi())
        throw Signed("that form isn't signed!!");
    if (executor.getGrade() > getGrade_ex())
        throw GradeTooLowException("Grade too low!!");
    str = target + "_shrubbery";
    outfile.open(str.c_str(), std::ios::out | std::ios::trunc);
    if (!outfile)
    {
        std::cout << "error in opening file !";
        throw std::runtime_error("Failed to create file: " + target + "_shrubbery");
    }
    outfile << "       _-_\n";
    outfile << "    /~~   ~~\\\n";
    outfile << " /~~         ~~\\\n";
    outfile << "{               }\n";
    outfile << " \\  _-     -_  /\n";
    outfile << "   ~  \\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\n";
    outfile.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
    if (this != &op)
        (*this).target = op.target;
    return (*this);
}

ShrubberyCreationForm::Signed::~Signed() throw()
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
