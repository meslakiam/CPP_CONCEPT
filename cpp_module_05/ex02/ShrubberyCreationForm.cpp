#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), _target(""), _gradeToSign(145), _gradeToExec(137)
{
    this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
    : AForm("Shrubbery Creation Form", 145, 137), _target(target), _gradeToSign(145), _gradeToExec(137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& other )
    : AForm("Shrubbery Creation Form", 145, 137), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    this->_target = other._target;

}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( ShrubberyCreationForm& other )
{
    if ( this == &other )
        return ( *this );

    this->_target = other._target;

    return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void         ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ( !AForm::getSign() )
        throw AForm::NotSignedException();
    if( executor.GetGrade() > this->_gradeToExec )
        throw AForm::GradeTooLowException();

    std::ofstream   file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    file << "                                                       .          \n";
    file << "                                            .         ;           \n";
    file << "               .              .              ;%     ;;            \n";
    file << "                 ,           ,                :;%  %;             \n";
    file << "                  :         ;                   :;%;'     .,      \n";
    file << "         ,.        %;     %;            ;        %;'    ,;        \n";
    file << "           ;       ;%;  %%;        ,     %;    ;%;    ,%'         \n";
    file << "            %;       %;%;      ,  ;       %;  ;%;   ,%;'          \n";
    file << "             ;%;      %;        ;%;        % ;%;  ,%;'            \n";
    file << "              `%;.     ;%;     %;'         `;%%;.%;'              \n";
    file << "               `:;%.    ;%%. %@;        %; ;@%;%'                 \n";
    file << "                  `:%;.  :;bd%;          %;@%;'                   \n";
    file << "                    `@%:.  :;%.         ;@@%;'                    \n";
    file << "                      `@%.  `;@%.      ;@@%;                      \n";
    file << "                        `@%%. `@%%    ;@@%;                       \n";
    file << "                          ;@%. :@%%  %@@%;                        \n";
    file << "                            %@bd%%%bd%%:;                         \n";
    file << "                              #@%%%%%:;;                          \n";
    file << "                              %@@%%%::;                           \n";                                  
    file << "                              %@@@%(o);  .'                       \n";
    file << "                              %@@@o%;:(.,'                        \n";
    file << "                          `.. %@@@o%::;                           \n";
    file << "                             `)@@@o%::;                           \n";
    file << "                              %@@(o)::;                           \n";
    file << "                             .%@@@@%::;                           \n";
    file << "                             ;%@@@@%::;.                          \n";
    file << "                            ;%@@@@%%:;;;.                         \n";
    file << "                        ...;%@@@@@%%:;;;;,..;                     \n";


    file << "\n\n\n\n\n\n                                                       \n";
    file << "                               ,@@@@@@@,                           \n";
    file << "                       ,,,.   ,@@@@@@/@@,  .oo8888o.               \n";
    file << "                    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o             \n";
    file << "                   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'          \n";
    file << "                   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'           \n";
    file << "                   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'            \n";
    file << "                   `&%\\ ` /%&'    |.|        \\ '|8'              \n";
    file << "                       |o|        | |         | |                  \n";
    file << "                       |.|        | |         | |                  \n";
    file << "                    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_       \n";

    file.close();
}
