#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    try {
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    Bureaucrat a("V", 44);
    a.signAForm(*rrf);
    a.executeForm(*rrf);
    
    std::cout << "----" << std::endl;

    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    a.signAForm(*scf);
    a.executeForm(*scf);
    
    delete rrf;
    delete scf;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    AForm* zpf;
    try {
        zpf = someRandomIntern.makeForm("NOT FOUND FORM", "nothing");
        delete zpf;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
