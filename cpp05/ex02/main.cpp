#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm roboForm("Bender");
        RobotomyRequestForm roboForm2("Bender2");
        RobotomyRequestForm roboForm3("Bender3");
        PresidentialPardonForm pardonForm("Marvin");

        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;

        bob.signForm(shrubForm);
        bob.signForm(roboForm);
        bob.signForm(roboForm2);
        bob.signForm(roboForm3);
        bob.signForm(pardonForm);

        std::cout << std::endl;

        bob.executeForm(shrubForm);
        bob.executeForm(roboForm);
        bob.executeForm(roboForm2);
        bob.executeForm(roboForm3);
        bob.executeForm(pardonForm);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}