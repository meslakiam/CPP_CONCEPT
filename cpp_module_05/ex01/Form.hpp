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

        std::string const   getName() const;
        bool                getSign() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;
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

std::ostream&    operator<<(std::ostream& os, Form& obj);

#endif