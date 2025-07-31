#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 1);

        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "Home");
        std::cout << *shrubForm << std::endl;

        alice.signForm(*shrubForm);
        alice.executeForm(*shrubForm);

        AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *robotForm << std::endl;

        alice.signForm(*robotForm);
        alice.executeForm(*robotForm);

        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Marvin");
        std::cout << *pardonForm << std::endl;

        alice.signForm(*pardonForm);
        alice.executeForm(*pardonForm);

        try {
            AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Target");

			alice.signForm(*unknownForm);
        	alice.executeForm(*unknownForm);
            delete unknownForm;  // Just in case
        } catch (std::exception &e) {
            std::cout << "Intern error: " << e.what() << std::endl;
        }

        delete shrubForm;
        delete robotForm;
        delete pardonForm;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}