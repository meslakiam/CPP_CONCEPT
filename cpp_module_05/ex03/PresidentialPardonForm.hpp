#ifndef PRESIDENTIALPARADONFORM_HPP
#define PRESIDENTIALPARADONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        int const   _gradeToSign;
        int const   _gradeToExec;

        PresidentialPardonForm();
            
    public:
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm(PresidentialPardonForm& other);
        PresidentialPardonForm&  operator=(PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void        execute(Bureaucrat const & executor) const;
};

#endif