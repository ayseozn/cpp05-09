#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        try {
        Bureaucrat a("a1", 25);
        Bureaucrat b("b1", 1);
        AForm* rqf = new RobotomyRequestForm("ROBOT");
        PresidentialPardonForm ppf("McQueen");
        
        a.signAForm(*rqf);
        a.signAForm(ppf);
        std::cout << "-----" << std::endl;
        a.executeForm(*rqf);
        a.executeForm(ppf);
        b.executeForm(ppf);
        std::cout << "-----" << std::endl;
        Bureaucrat a2("a2");
        ShrubberyCreationForm scf("shrubbery");
        b.signAForm(scf);
        b.executeForm(scf);
        delete rqf;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
}
