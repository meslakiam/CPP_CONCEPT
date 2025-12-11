#include "AForm.hpp"

AForm::AForm() : _name(""), _gradeToSign(1), _gradeToExec(1) 
{
    this->_isSigned = false;
}

AForm::AForm(std::string const   name,int const gradeToSign, int const gradeToExec)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    this->_isSigned = false;
}

AForm::AForm(AForm&  other)
    : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)  
{
    this->_isSigned = other._isSigned;
}

AForm&   AForm::operator=(AForm& other)
{
    if( this == &other )
        return ( *this );

    this->_isSigned = other._isSigned;

    return ( *this );
}

AForm::~AForm() {}

std::string const   AForm::getName() const
{
    return ( this->_name );
}

int           AForm::getGradeToSign() const
{
    return ( this->_gradeToSign );
}

int           AForm::getGradeToExecute() const
{
    return ( this->_gradeToExec );
}

bool    AForm::getSign() const
{
    return ( this->_isSigned );
}

void    AForm::beSigned(Bureaucrat&  bureaucrat)
{
    if( bureaucrat.GetGrade() > this->_gradeToSign)
        throw( AForm::GradeTooLowException() );

    this->_isSigned = true;
}

const char*     AForm::GradeTooHighException::what() const throw()
{
    return ( "Grade too High" );
}

const char*     AForm::GradeTooLowException::what() const throw()
{
    return ( "Grade too low" );
}


const char*     AForm::NotSignedException::what() const throw()
{
    return ( "The Form Not Signed" );
}

std::ostream&    operator<<(std::ostream& os, AForm& obj)
{
    os << "the " << obj.getName() << " Form has grade To Sign: " << obj.getGradeToSign();
    os << ", and grade to execute: " << obj.getGradeToExecute();

    return ( os );
}
