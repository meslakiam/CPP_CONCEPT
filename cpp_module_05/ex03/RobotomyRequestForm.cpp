#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), _gradeToSign(72), _gradeToExec(45)
{
    this->_target = "";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
    : AForm("Robotomy Request Form", 72, 45), _gradeToSign(72), _gradeToExec(45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
    : AForm("Robotomy Request Form", 72, 45), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    this->_target = other._target;

}

RobotomyRequestForm&  RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
    if ( this == &other )
        return ( *this );

    this->_target = other._target;

    return ( *this );
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if ( !this->getSign() )
        throw AForm::NotSignedException();
    if( executor.GetGrade() > this->_gradeToExec )
        throw AForm::GradeTooLowException();

    std::cout << "DRR DDDR RD R RRR RNNN" << std::endl;
    srand(time(NULL));
    if( rand() % 2 )
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout <<  "robotomy failed" << std::endl;
}
