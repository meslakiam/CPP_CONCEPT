#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>
#include <time.h> 

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        int const   _gradeToSign;
        int const   _gradeToExec;

        RobotomyRequestForm();

    public:
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm(RobotomyRequestForm& other);
        RobotomyRequestForm&  operator=(RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void        execute(Bureaucrat const & executor) const;
};

#endif