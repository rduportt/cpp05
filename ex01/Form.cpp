#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(false), _grade_signed(0), _grade_exec(0)
{
}

Form::Form(std::string const name, bool ssigned, int const grade_signed, int const grade_exec) : _name(name) ,_signed(ssigned), _grade_signed(grade_signed), _grade_exec(grade_exec)
{
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _grade_signed(other._grade_signed), _grade_exec(other._grade_exec)
{
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat bureaucrat)
{
    if(bureaucrat.GetGrade() > _grade_signed)
        throw(GradeTooLowExeception());
    _signed = true;
}

std::string const Form::GetName() const
{
    return _name;
}

int Form::GetGradeSigned() const
{
    return _grade_signed;
}

int Form::GetGradeExec() const
{
    return _grade_exec;
}

bool Form::GetSigned() const
{
    return _signed;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.GetName() << ", grade required to sign the form : " << form.GetGradeSigned() << ". ";
    if(form.GetSigned() == true)
        out << "The form is signed";
    else
        out << "The form is not signed";
    return out;
}