#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("presidential pardon", 25, 5)
{
    this->target = "default";}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("presidential pardon", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm::AForm("presidential pardon", 25, 5)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if ( this == &other)
        return *this;
    target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::specificExecute(void) const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
