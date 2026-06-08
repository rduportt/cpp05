#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat Jean("Jean", 2);
        PresidentialPardonForm test_presidential("home");
        Jean.signAForm(test_presidential);
        Jean.executeAForm(test_presidential);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n\n";
    try
    {
        Bureaucrat Jean("Jean", 100);
        ShrubberyCreationForm test_shrubbery("home");
        Jean.signAForm(test_shrubbery);
        Jean.executeAForm(test_shrubbery);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n\n";
    try
    {
        Bureaucrat Jean("Jean", 30);
        RobotomyRequestForm test_robotomy("home");
        Jean.signAForm(test_robotomy);
        Jean.executeAForm(test_robotomy);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}