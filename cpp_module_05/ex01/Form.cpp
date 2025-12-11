#include "Form.hpp"

Form::Form() : _name(""), _gradeToSigned(1), _gradeToExecute(1) 
{
    this->_signed = false;
}

Form::Form(std::string const  name, int const GToSigned, int const  GToExecute)
    : _name(name), _gradeToSigned(GToSigned), _gradeToExecute(GToExecute)
{
    if( this->_gradeToSigned > 150 || this->_gradeToExecute > 150)
        throw( Form::GradeTooLowException() );
    if( this->_gradeToSigned < 1 || this->_gradeToExecute < 1)
        throw( Form::GradeTooHighException() );

    this->_signed = false;
}
Form::Form(Form&  other)
    : _name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute)  
{
    if( this->_gradeToSigned > 150 || this->_gradeToExecute > 150)
        throw( Form::GradeTooLowException() );
    if( this->_gradeToSigned < 1 || this->_gradeToExecute < 1)
        throw( Form::GradeTooHighException() );

    this->_signed = other._signed;
}

Form&   Form::operator=(Form& other)
{
    if( this == &other )
        return ( *this );

    this->_signed = other._signed;

    return ( *this );
}

Form::~Form() {}

std::string const   Form::getName() const
{
    return ( this->_name );
}

int           Form::getGradeToSign() const
{
    return ( this->_gradeToSigned );
}

int           Form::getGradeToExecute() const
{
    return ( this->_gradeToExecute );
}

bool    Form::getSign() const
{
    return ( this->_signed );
}

void    Form::beSigned(Bureaucrat&  bureaucrat)
{
    if(bureaucrat.GetGrade() > this->_gradeToSigned)
        throw( Form::GradeTooLowException() );

    this->_signed = true;
}

const char*     Form::GradeTooHighException::what() const throw()
{
    return ( "Grade too High" );
}

const char*     Form::GradeTooLowException::what() const throw()
{
    return ( "Grade too low" );
}

std::ostream&    operator<<(std::ostream& os, Form& obj)
{
    os << "the " << obj.getName() << " Form has grade To Sign: " << obj.getGradeToSign();
    os << ", and grade to execute: " << obj.getGradeToExecute();

    return ( os );
}
