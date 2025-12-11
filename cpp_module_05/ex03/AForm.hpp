#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>  

class   AForm {

    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExec;

    protected:
        AForm(std::string const   name, int const gradeToSign, int const gradeToExec);

    public:
        AForm();
        AForm(AForm&  other);
        AForm&   operator=(AForm& other);
        virtual ~AForm();

        bool                getSign() const;
        std::string const   getName() const;
        void        beSigned( Bureaucrat&   bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char*  what() const throw();
        };

        class GradeTooLowException : public std::exception {
           public: 
            const char*  what() const throw();
        };

        class NotSignedException : public std::exception {
           public: 
            const char*  what() const throw();
        };
};

#endif