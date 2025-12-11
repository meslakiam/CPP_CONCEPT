#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), _gradeToSign(25), _gradeToExec(5)
{
    this->_target = "";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
    : AForm("Presidential Pardon Form", 25, 5), _gradeToSign(25), _gradeToExec(5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
    : AForm("Presidential Pardon Form", 25, 5), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    this->_target = other._target;
}

PresidentialPardonForm&     PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
    if ( this == &other )
        return ( *this );

    this->_target = other._target;

    return ( *this );
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if ( !this->getSign() )
        throw AForm::NotSignedException();
    if( executor.GetGrade() > this->_gradeToExec )
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
