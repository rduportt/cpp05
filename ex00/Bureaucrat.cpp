#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(NULL) , _grade(150)
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

void    Bureaucrat::incrementGrade()
{
    if(_grade - 1 < 1)
        throw(GradeTooHighException());
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade + 1 > 150)
        throw(GradeTooLowException());
    _grade++;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << ".";
    return out;
}