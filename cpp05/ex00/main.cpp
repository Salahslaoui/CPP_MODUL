#include "Bureaucrat.hpp"

int main()
{
	try {
			Bureaucrat b1("Alice", 42);
			std::cout << b1 << std::endl;

			std::cout << "Incrementing grade..." << std::endl;
			while (true) {
				b1.incr();
				std::cout << b1 << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

    try {
        Bureaucrat b2("Bob", 0);
    } catch (std::exception &e) {
        std::cerr << "Exception caught during creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151);
    } catch (std::exception &e) {
        std::cerr << "Exception caught during creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Dave", 149);
        std::cout << b4 << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        while (true) {
            b4.decr();
            std::cout << b4 << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}