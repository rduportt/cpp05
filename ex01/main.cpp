#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Jean("Jean", 100);
        Form test_form("test_form", false, 150, 120);
        Jean.signForm(test_form);
        std::cout << Jean << std::endl << test_form << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n\n";
    try
    {
        Bureaucrat Jean("Jean", 150);
        Form test_form("test_form", false, 120, 120);
        Jean.signForm(test_form);
        std::cout << Jean << std::endl << test_form << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}