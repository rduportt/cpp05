#ifndef AForm_HPP_
#define AForm_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string const name, bool ssigned, int const grade_signed, int const grade_exec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        void beSigned(const Bureaucrat bureaucrat); 
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighExeception : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Grade too high";
            }
        };
        class GradeTooLowExeception : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Grade too low";
            }
        };
        std::string const   GetName() const;
        int   GetGradeSigned() const;
        int   GetGradeExec() const;
        bool  GetSigned() const;
    protected :
        std::string const _name;
        bool _signed;
        int const _grade_signed;
        int const _grade_exec;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);


#endif