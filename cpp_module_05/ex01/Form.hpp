#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class   Form {
    
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSigned;
        int const           _gradeToExecute;
        Form();

    public:
        Form(std::string const  name, int const GToSigned, int const  GToExecute);
        Form(Form&  other);
        Form&   operator=(Form& other);
        ~Form();

        bool                getSign();
        std::string const   getName();
        void                beSigned( Bureaucrat&   bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char*  what() const throw();
        };

        class GradeTooLowException : public std::exception {
           public: 
            const char*  what() const throw();
        };
};

#endif