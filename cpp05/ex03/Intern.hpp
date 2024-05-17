#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class  Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern &operator=(const Intern &other);
    ~Intern();

    class FormNotFoundException: public std::exception {
        const char* what() const throw();
    };

    AForm*  makePresidentialPardon(std::string target);
    AForm*  makeRobotomyRequest(std::string target);
    AForm*  makeShrubberyCreation(std::string target);
    AForm*  makeForm(std::string formName, std::string formTarget);
};

#endif