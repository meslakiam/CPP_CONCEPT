#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class   Intern {

    private:
        AForm*  shrubbery(std::string target);
        AForm*  robotomy(std::string target);
        AForm*  presidential(std::string target);
        AForm*  CreateForm(std::string formName, std::string target);
    public:
        Intern();
        Intern(Intern& other);
        Intern& operator=(Intern& other);
        ~Intern();

        AForm*   makeForm(std::string formName, std::string target);

        class InvalidFormName : public std::exception {
           public: 
            const char*  what() const throw();
        };
};


#endif