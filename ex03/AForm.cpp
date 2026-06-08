#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _signed(false), _grade_signed(0), _grade_exec(0)
{
}

AForm::AForm(std::string const name, bool ssigned, int const grade_signed, int const grade_exec) : _name(name) ,_signed(ssigned), _grade_signed(grade_signed), _grade_exec(grade_exec)
{
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _grade_signed(other._grade_signed), _grade_exec(other._grade_exec)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat bureaucrat)
{
    if(bureaucrat.GetGrade() > _grade_signed)
        throw(GradeTooLowExeception());
    _signed = true;
}

std::string const AForm::GetName() const
{
    return _name;
}

int AForm::GetGradeSigned() const
{
    return _grade_signed;
}

int AForm::GetGradeExec() const
{
    return _grade_exec;
}

bool AForm::GetSigned() const
{
    return _signed;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.GetName() << ", grade required to sign the AForm : " << AForm.GetGradeSigned() << ". ";
    if(AForm.GetSigned() == true)
        out << "The AForm is signed";
    else
        out << "The AForm is not signed";
    return out;
}

void AForm::execute(Bureaucrat const &executor) const
{
    (void)(executor);
}