#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default Aform"), isSigned(false), requiredGradeToExecute(150), requiredGradeToSign(150)
{}

AForm::AForm(std::string Name): name(Name), requiredGradeToExecute(150), requiredGradeToSign(150), isSigned(false)
{}

AForm::AForm(std::string Name, int gradeToSign, int gradeToExecute): name(Name),
 isSigned(false), requiredGradeToExecute(gradeToExecute), requiredGradeToSign(gradeToSign)
{
    if(gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    else if(gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.getName()), requiredGradeToExecute(other.getGradeToExec()), requiredGradeToSign(other.getGradeToSign())
{
    *this = other;
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this == &other)
        return *this;
    this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return (name);
}

std::string AForm::getIsSigned() const
{
    if (isSigned)
        return ("true");
    else
        return "false";
}

int AForm::getGradeToExec() const
{
    return (requiredGradeToExecute);
}

int AForm::getGradeToSign() const
{
    return requiredGradeToSign;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form not signed!";
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() >= requiredGradeToExecute)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << name << std::endl;
    specificExecute();
}

std::ostream& operator<<(std::ostream& o, const AForm& other)
{
    o << other.getName() << ", requried grade to sign " << other.getGradeToSign()
    << ", required grade to execute " <<other.getGradeToExec() << ", is signed " <<  other.getIsSigned() << std::endl;
    return o;
}
