#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>


class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int requiredGradeToSign;
    const int requiredGradeToExecute;

public:
    AForm();
    AForm(std::string Name);
    AForm(std::string Name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

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
    class FormNotSignedException: public std::exception
    {
        const char* what() const throw();
    };

    void    beSigned(Bureaucrat& bureaucrat);
    void    execute(Bureaucrat const & executor) const;
    virtual void specificExecute(void) const = 0;

};

std::ostream &operator<<(std::ostream& o, const AForm& other);


#endif