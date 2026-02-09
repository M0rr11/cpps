#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        b1.incrementGrade(); // This will throw an exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 151); // This will throw an exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}