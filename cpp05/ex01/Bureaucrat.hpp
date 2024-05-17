#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string Name);
    Bureaucrat(std::string Name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void setGrade(int grade);

    void    increaseDegree();
    void    reduce_degree();

    class GradeTooHighException: public std::exception 
    {
        const char* what() const throw();
    };
    class GradeTooLowException: public std::exception 
    {
        const char* what() const throw();
    };

    void    signForm(Form& form);
};

std::ostream &operator<<(std::ostream& o, const Bureaucrat& other);

#endif