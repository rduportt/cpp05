#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("")
{   
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other.getTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    if(!GetSigned())
        throw AForm::GradeTooLowExeception();
    if(bureaucrat.GetGrade() > GetGradeExec())
        throw AForm::GradeTooLowExeception();
   FileTrees(_target);
}

void FileTrees(std::string target)
{
    std::string filename = target + "_shrubbery";
    std::ofstream MyFile(filename.c_str());

    for(int i = 0; i < 3; i++)
    {
        MyFile <<
        "         v" << std::endl <<
        "        >X<" << std::endl <<
        "         A" << std::endl <<
        "        d$b" << std::endl <<
        "      .d\\$$b." << std::endl <<
        "    .d$i$$\\$$b." << std::endl <<
        "       d$$@b" << std::endl <<
        "      d\\$$$ib" << std::endl <<
        "    .d$$$\\$$$b" << std::endl <<
        "  .d$$@$$$$\\$$ib." << std::endl <<
        "      d$$i$$b" << std::endl <<
        "     d\\$$$$@$b" << std::endl <<
        "  .d$@$$\\$$$$$@b." << std::endl <<
        ".d$$$$i$$$\\$$$$$$b." << std::endl <<
        "        ###" << std::endl <<
        "        ###" << std::endl <<
        "        ###" << std::endl << std::endl;
    }
    MyFile.close();
}

std::string	const ShrubberyCreationForm::getTarget()const
{
	return _target;
}
