#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("ShrubberyCreationForm", false, 25, 5), _target("")
{   
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("ShrubberyCreationForm", false, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other.getTarget())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    if(!GetSigned())
        throw AForm::GradeTooLowExeception();
    if(bureaucrat.GetGrade() > GetGradeExec())
        throw AForm::GradeTooLowExeception();
    std::cout << _target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}

std::string const	PresidentialPardonForm::getTarget()const
{
	return _target;
}

