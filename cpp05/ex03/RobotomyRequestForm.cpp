#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "Bzzzz... " << target << " has been robotomized successfully 50% of the time." << std::endl;
}


