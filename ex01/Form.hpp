# ifndef FORM_HPP_
#define FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string const name, bool ssigned, int const grade_signed, int const grade_exec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        void beSigned(const Bureaucrat bureaucrat);

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
    private :
        std::string const _name;
        bool _signed;
        int const _grade_signed;
        int const _grade_exec;
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif