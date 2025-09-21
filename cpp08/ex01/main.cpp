#include "Span.hpp"
#include <cstdlib>
#include <ctime>


int main() 
{
    std::srand(std::time(NULL)); // seed RNG


    std::cout << "\n[Basic Functionality Tests]" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(9);
        sp.addNumber(1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // expect 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // expect 8
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << "\n[Capacity Tests]" << std::endl;
    Span small(3);
    try {
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3);
        small.addNumber(4); // should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception (expected): " << e.what() << std::endl;
    }


    std::cout << "\n[Exception Safety]" << std::endl;
    Span empty(5);
    try {
        empty.shortestSpan(); // should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try {
        empty.longestSpan(); // should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }


    std::cout << "\n[Big Data Test: 10,000 numbers]" << std::endl;
    Span big(10000);
    for (int i = 0; i < 10000; i++) {
        big.addNumber(i); // sequential
    }
    std::cout << "Sequential shortest span: " << big.shortestSpan() << " (expected 1)" << std::endl;
    std::cout << "Sequential longest span: " << big.longestSpan() << " (expected 9999)" << std::endl;

    try
    {
        std::cout << "\n[All Identical Numbers]" << std::endl;
        Span same(5);
        for (int i = 0; i < 5; i++) same.addNumber(42);
        std::cout << "Shortest span: " << same.shortestSpan() << " (expected 0)" << std::endl;
        std::cout << "Longest span: " << same.longestSpan() << " (expected 0)" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n[Random Numbers]" << std::endl;
    Span randSpan(10000);
    for (int i = 0; i < 10000; i++) {
        randSpan.addNumber(std::rand());
    }
    std::cout << "Random shortest span: " << randSpan.shortestSpan() << std::endl;
    std::cout << "Random longest span: " << randSpan.longestSpan() << std::endl;


    std::cout << "\n[Range Insertion Test]" << std::endl;
    std::vector<int> vec(100);
    std::generate(vec.begin(), vec.end(), std::rand);
    Span rangeTest(100);
    rangeTest.addRange<std::vector<int> >(vec.begin(), vec.end());
    std::cout << "Range shortest span: " << rangeTest.shortestSpan() << std::endl;
    std::cout << "Range longest span: " << rangeTest.longestSpan() << std::endl;

    return 0;
}