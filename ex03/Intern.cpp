#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other) 
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    if(this == &other)
        return *this;
    return *this;
}

Intern::~Intern()
{
}

static AForm *makeRobotomy(std::string target)
{
    return(new RobotomyRequestForm(target));
}

static AForm *makePresidential(std::string target)
{
    return(new PresidentialPardonForm(target));
}

static AForm *makeShrubbery(std::string target)
{
    return(new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string nameForm, std::string targetForm)
{
    std::string forms[] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
    AForm *(*all_forms[])(const std::string target) = {&makeRobotomy, &makePresidential, &makeShrubbery};

    for (int i = 0; i < 3; i++)
    {
        if(nameForm == forms[i])
        {
            std::cout << "Intern creates " << nameForm << std::endl;
            return(all_forms[i](targetForm));
        }
    }
    std::cout << nameForm << " is not a valid Form name" << std::endl << "Valid form names are : RobotomyRequestForm, PresidentialPardonForm, ShrubberyCreationForm" << std::endl;
    return(NULL);
}