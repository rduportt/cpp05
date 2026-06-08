#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern intern;

    std::cout << "--- Test 1: RobotomyRequestForm ---" << std::endl;
    AForm *form1 = intern.makeForm("RobotomyRequestForm", "Bender");
    std::cout << std::endl;

    std::cout << "--- Test 2: PresidentialPardonForm ---" << std::endl;
    AForm *form2 = intern.makeForm("PresidentialPardonForm", "Alice");
    std::cout << std::endl;

    std::cout << "--- Test 3: ShrubberyCreationForm ---" << std::endl;
    AForm *form3 = intern.makeForm("ShrubberyCreationForm", "Home");
    std::cout << std::endl;

    std::cout << "--- Test 4: Invalid form ---" << std::endl;
    AForm *form4 = intern.makeForm("InvalidForm", "Target");
    std::cout << std::endl;

    delete form1;
    delete form2;
    delete form3;
    if (form4)
        delete form4;

    return 0;
}