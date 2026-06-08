#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("ShrubberyCreationForm", false, 72, 45), _target("")
{   
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("ShrubberyCreationForm", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    int rand;
    if(!GetSigned())
        throw AForm::GradeTooLowExeception();
    if(bureaucrat.GetGrade() > GetGradeExec())
        throw AForm::GradeTooLowExeception();
    rand = std::rand() % 2;
    if(rand == 1)
        std::cout << _target << " has been robotomized successfully !" << std::endl;
    else
        std::cout << _target << " couldn't be robotomized >:(" << std::endl;
}

std::string const	RobotomyRequestForm::getTarget()const
{
	return _target;
}
