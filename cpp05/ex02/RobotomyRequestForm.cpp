#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("robotomy request", 72, 45)
{this->target = "Default";}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("robotomy request", 72, 45)
{this->target = target;}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm::AForm("robotomy request", 72, 45)
{*this = other;}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::specificExecute() const
{
    std::srand(time(0));
    size_t t = std::rand();
    std::cout << "*DRILLING NOISES*" << std::endl;
    if (t % 2 == 0)
        std::cout << target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy " <<target << " failed!" << std::endl; 
}
