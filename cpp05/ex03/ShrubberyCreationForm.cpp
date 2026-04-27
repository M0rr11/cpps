#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    
    std::ofstream outFile((target + "_shrubbery").c_str())  ;
    if (!outFile)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;

    outFile.close();
}
