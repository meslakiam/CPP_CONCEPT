#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        int const   _gradeToSign;
        int const   _gradeToExec;

        ShrubberyCreationForm();
            
    public:
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm& other );
        ShrubberyCreationForm&  operator=( ShrubberyCreationForm& other );
        ~ShrubberyCreationForm();

        void        execute(Bureaucrat const & executor) const;

};

#endif