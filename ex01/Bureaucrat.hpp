# ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat
{
    public :
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(Bureaucrat const& other);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Grade too high.";
            }
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Grade too low";
            }
        };
        std::string const   GetName() const;
        int                 GetGrade() const;

        void    incrementGrade();
        void    decrementGrade();
        void    signForm(Form &form);


    private :
        std::string const   _name;
        int                 _grade; //1 - 150
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif