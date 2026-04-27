#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    typedef AForm *(*FormCreator)(const std::string &);
    FormCreator formCreators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }
    std::cerr << "Intern cannot create form: " << formName << std::endl;
    throw std::invalid_argument("Unknown form name: " + formName);
}
