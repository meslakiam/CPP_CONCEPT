#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern& other) {(void)other; }

Intern& Intern::operator=(Intern& other)
{
    if( this == &other )
        return ( *this );

    return ( *this );
}
AForm*  Intern::shrubbery(std::string target)
{
    return ( new ShrubberyCreationForm(target) );
}

AForm*  Intern::robotomy(std::string target)
{
    return ( new RobotomyRequestForm(target) );
}

AForm*  Intern::presidential(std::string target)
{
    return ( new PresidentialPardonForm(target) );
}

Intern::~Intern() {}

AForm*  Intern::CreateForm(std::string formName, std::string target)
{
    std::string name[3] = { 
        "presidential pardon" 
        ,"robotomy request", 
        "shrubbery creation"
    };    

    AForm* (Intern::*ptr[3])(std::string) = {
        &Intern::presidential,
        &Intern::robotomy,
        &Intern::shrubbery
    };

    for (size_t i = 0; i < 3; i++)
    {
        if( formName == name[i] )
            return (this->*ptr[i])(target);
    }
    throw InvalidFormName();
    
}

AForm*   Intern::makeForm(std::string formName, std::string target)
{
    
    try
    {
        AForm *form = CreateForm(formName, target);
        std::cout << "Intern creates " << formName << " Form" << std::endl;
        return ( form );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

const char*  Intern::InvalidFormName::what() const throw()
{
    return ( "Invalid Form Name" );
}
