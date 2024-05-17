#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern(){}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Intern: Form Not Found";
}

AForm *Intern::makePresidentialPardon(std::string target) {
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string target) {
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreation(std::string target) {
    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm* (Intern::*ptr[3])(std::string) = {
        &Intern::makePresidentialPardon,
        &Intern::makeRobotomyRequest,
        &Intern::makeShrubberyCreation,
    };
    
    for (size_t i = 0; i < 3; ++i) {
        if (names[i] == name)
            return (this->*ptr[i])(target);
    }
    throw Intern::FormNotFoundException();
}
