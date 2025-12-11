#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP

#include <iostream>

class AForm;

class   Bureaucrat {

    private:
        std::string const _name;
        int _grade;
        Bureaucrat();

    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();

        std::string const       GetName() const ;
        int                     GetGrade() const ;
        void                    IncrementGrade(int add);
        void                    DecrementGrade(int add);
        void                    signForm(AForm&  form);
        void                    executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception {
            public:
                const char*  what() const throw();
        };

        class GradeTooLowException : public std::exception {
           public: 
            const char*  what() const throw();
        };

};

std::ostream&   operator<<(std::ostream& os, Bureaucrat& obj);

#endif