#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default form"), isSigned(false), requiredGradeToExecute(150), requiredGradeToSign(150)
{}

Form::Form(std::string Name): name(Name), requiredGradeToExecute(150), requiredGradeToSign(150), isSigned(false)
{}

Form::Form(std::string Name, int gradeToSign, int gradeToExecute): name(Name),
 isSigned(false), requiredGradeToExecute(gradeToExecute), requiredGradeToSign(gradeToSign)
{
    if(gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    else if(gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.getName()), requiredGradeToExecute(other.getGradeToExec()), requiredGradeToSign(other.getGradeToSign())
{
    *this = other;
}

Form&   Form::operator=(const Form& other)
{
    if (this == &other)
        return *this;
    this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{}

std::string Form::getName() const
{
    return (name);
}

std::string Form::getIsSigned() const
{
    if (isSigned)
        return ("true");
    else
        return "false";
}

int Form::getGradeToExec() const
{
    return (requiredGradeToExecute);
}

int Form::getGradeToSign() const
{
    return requiredGradeToSign;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade Too Low";
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const Form& other)
{
     o << other.getName() << ", requried grade to sign " << other.getGradeToSign()
    << ", required grade to execute " <<other.getGradeToExec() << ", is signed " <<  other.getIsSigned() << std::endl;
    return o;
}
