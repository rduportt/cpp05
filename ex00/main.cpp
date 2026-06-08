#include "Bureaucrat.hpp"

int main()
{

    try
    {
        Bureaucrat Jean("Jean", 140);
        std::cout << Jean << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Claude("Claude", 149);
        std::cout << Claude << std::endl;
        Claude.decrementGrade();
        std::cout << Claude << std::endl;
        Claude.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}