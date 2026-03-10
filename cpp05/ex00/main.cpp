#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Nyx", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Hemera", 150);
        std::cout << b2 << std::endl;

        b1.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Hera", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}