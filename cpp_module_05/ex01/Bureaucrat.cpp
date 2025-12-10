#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if ( grade < 1 )
        throw GradeTooHighException();
    if ( grade > 150 )
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat&     Bureaucrat::operator=(Bureaucrat& other)
{
    if(this == &other)
        return ( *this );

    this->_grade = other._grade;

    return ( *this );
}

Bureaucrat::~Bureaucrat() {}

std::string const    Bureaucrat::GetName()
{
    return ( this->_name );
}

int    Bureaucrat::GetGrade()
{
    return ( this->_grade );
}

void    Bureaucrat::IncrementGrade(int add)
{
    if( (this->_grade - add) < 1 )
        throw GradeTooHighException();
    if( (this->_grade - add) > 150 )
        throw GradeTooLowException();
    this->_grade -= add;
}

void    Bureaucrat::DecrementGrade(int add)
{
    if( (this->_grade + add) < 1 )
        throw GradeTooHighException();
    if( (this->_grade + add) > 150 )
        throw GradeTooLowException();
    this->_grade += add;
}

void    Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned( *this );
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch ( std::exception& e )
    {
        std::cout << this->_name << " couldn't sign " << form.getName();
        std::cout << " because " << e.what() << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& os, Bureaucrat& obj)
{
    os << obj.GetName() << ", bureaucrat grade " << obj.GetGrade();

    return ( os );
}

const char*     Bureaucrat::GradeTooHighException::what() const throw()
{
    return ( "Grade too High" );
}

const char*     Bureaucrat::GradeTooLowException::what() const throw()
{
    return ( "Grade too low" );
}
