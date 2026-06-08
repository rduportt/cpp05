#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : _name("") , _grade(150)
{
    std::cout << "Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if(grade > 150)
        throw(GradeTooLowException());
    if(grade < 1)
        throw(GradeTooHighException());
    _grade = grade;
    std::cout << "Parameterized constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) , _grade(other._grade)
{
    std::cout << "Copy constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Operator constructor called" << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Called" << std::endl;
}

std::string const Bureaucrat::GetName() const
{
    return _name;
}

int Bureaucrat::GetGrade() const
{
    return _grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << ".";
    return out;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		std::cout << "Trying to increment grade of " << this->GetName() << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << this->GetName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "Trying to decrement grade of " << this->GetName() << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of " << this->GetName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::signAForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << GetName() << " signed " << AForm.GetName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << GetName() << " couldn't sign " << AForm.GetName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeAForm(AForm const &form) const
{
    form.execute(*this);
    std::cout << GetName() << " executed " << form.GetName() << std::endl;
}