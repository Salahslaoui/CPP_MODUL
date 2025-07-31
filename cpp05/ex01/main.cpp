#include "Form.hpp"

int main() 
{
    try {
        Bureaucrat alice("Alice", 15);
        Bureaucrat bob("Bob", 50);

        Form contract("Contract", 20, 10);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        alice.signForm(contract);
        bob.signForm(contract);

        std::cout << contract << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}