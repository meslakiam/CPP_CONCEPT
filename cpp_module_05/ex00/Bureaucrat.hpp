#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP

#include <iostream>

class   Bureaucrat {

    private:
        std::string const   _name;
        int                 _grade;
        Bureaucrat();

    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();

        std::string const       GetName();
        int                     GetGrade();
        void                    IncrementGrade(int add);
        void                    DecrementGrade(int add);

        class GradeTooHighException : public std::exception{
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