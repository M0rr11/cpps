#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Nyx", 1);
        std::cout << b1 << std::endl;

        Form f1("FormA", 5, 10);
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;

        Form f2("FormB", 150, 150);
        b1.signForm(f2);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}