#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int requiredGradeToSign;
    const int requiredGradeToExecute;

public:
    Form();
    Form(std::string Name);
    Form(std::string Name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    std::string getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    class GradeTooHighException: public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        const char* what() const throw();
    };

    void    beSigned(Bureaucrat& bureaucrat);

};

std::ostream &operator<<(std::ostream& o, const Form& other);

#endif