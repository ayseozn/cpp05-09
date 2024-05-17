#ifndef PRESİDENTİALPARDONFORM_HPP
#define PRESİDENTİALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string Target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    void specificExecute(void) const;
};

#endif