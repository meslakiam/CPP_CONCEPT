#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {(void)other;}

ScalarConverter&    ScalarConverter::operator=(ScalarConverter& other)
{
    if ( this == &other )
        return ( *this );

    return ( *this );
}

ScalarConverter::~ScalarConverter() {}


bool    ScalarConverter::ConvertToPseudo(std::string& literal)
{
    if ( literal == "-inff" || literal == "+inff" || literal == "nanf" )
    {
        std::cout << "char: impossible\n" << "int: " << "impossible\n";
        std::cout << "float: " << literal << "\ndouble: " << literal.substr(0, (literal.length() - 1));
        std::cout << std::endl;
        return ( true );
    }
    if ( literal == "-inf" || literal == "+inf" || literal == "nan" )
    {
        std::cout << "char: impossible\n" << "int: " << "impossible\n";
        std::cout << "float: " << (literal + 'f') << "\ndouble: " << literal;
        std::cout << std::endl;
        return ( true );
    }
    return ( false );
}

bool     ScalarConverter::IsFloatNum(std::string& literal)
{
    size_t j = 0;
    bool s = 0;
    if ( literal[0] == '-' || literal[0] == '+')
        j++;
    if ( j == literal.length() )
        return ( false );
    for (size_t i = j;  i < (literal.length() - 1); i++)
    {
        if ( s == false && literal[i] == '.')
        {
            s = true;
            continue;
        }
        if ( !isdigit( static_cast< unsigned char>(literal[i]) ) )
            return ( false );
    }

    return ( true );
}

float   ScalarConverter::ConvertToFLOAT(std::string& literal)
{
    if ( literal.empty())
        throw ScalarConverter::ERRORMSG("impossible");
    if ( IsFloatNum(literal) )
    {
         std::string tmp = literal;
        if (tmp[tmp.length() - 1] == 'f')
            tmp = tmp.substr(0, (tmp.length() - 1));

        float f;
        std::stringstream ss(tmp);

        ss >> f;
        return f;
    }
    else
        throw ScalarConverter::ERRORMSG("impossible");
}
bool     ScalarConverter::IsDoubleNum(std::string& literal)
{
    size_t j = 0;
    bool s = 0;

    if ( literal[0] == '-' || literal[0] == '+')
        j++;
    if ( j == literal.length() )
        return ( false );

    for (size_t i = j;  i < literal.length(); i++)
    {
        if ( s == false && literal[i] == '.')
        {
            s = true;
            continue;
        }
        if ( !isdigit( static_cast< unsigned char>(literal[i]) ) )
            return ( false );
    }

    return ( true );
}

double  ScalarConverter::ConvertToDOUBLE(std::string& literal)
{
    if (literal.empty())
        throw ScalarConverter::ERRORMSG("impossible");

    if (IsFloatNum(literal))
    {
         std::string tmp = literal;
        if (tmp[tmp.length() - 1] == 'f')
            tmp = tmp.substr(0, (tmp.length() - 1));

        double d;
        std::stringstream ss(tmp);

        ss >> d;
        return d;
    }
    else
        throw ScalarConverter::ERRORMSG("impossible");
}

char     ScalarConverter::IsChar(std::string& literal, int i)
{
    int c = static_cast<unsigned char >(literal[i]);
    if ( isdigit(literal[i]) && literal.length() == 1 )
        c = atoi(literal.c_str());

    else if (isdigit(literal[i]) && literal.length() == 3 )
        c = atoi(std::string(1, literal[i]).c_str());
    else if ( isdigit(literal[i]) )
        c = atoi(literal.c_str());

    if (!isascii(c))
        throw ScalarConverter::ERRORMSG("impossible");

    if (!isprint(c))
        throw ScalarConverter::ERRORMSG("Non displayable");

    return ( static_cast<char>(c) );
}

char    ScalarConverter::ConvertToCHAR(std::string& literal)
{
    int i = 0;
    if ( literal.length() == 3 && literal[0] == '\'' &&  literal[2] == '\'' )
        i = 1;

    char c = IsChar(literal, i);
    return ( c );
}

int     ScalarConverter::ConvertToINT(std::string& literal)
{
    bool dnum;
    bool fnum;
    dnum = IsDoubleNum( literal );
    fnum = IsFloatNum( literal );

    try
    {
        if  ( fnum == true )
            return ( static_cast<int>(ConvertToFLOAT( literal )) );

        else if  ( dnum == true )
            return ( static_cast<int>(ConvertToDOUBLE( literal )) );

        else
            throw  ScalarConverter::ERRORMSG("impossible") ;
    }
    catch(const std::exception& e)
    {
        throw  ScalarConverter::ERRORMSG(e.what());
    }

}

ScalarConverter::ERRORMSG::ERRORMSG(std::string errorMsg)
{
    this->_errorMsg = errorMsg;
}
const char* ScalarConverter::ERRORMSG::what() const throw()
{
    return ( this->_errorMsg.c_str() );
}

void    ScalarConverter::PrintToOutput(char c, int num, float numf, double numd, std::string* error)
{

    std::cout << "char: ";
    if( !error[0].empty() )
        std::cout << error[0] << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if( !error[1].empty() )
        std::cout << error[1] << std::endl;
    else
        std::cout << num << std::endl;

    std::cout << "float: ";
    if( !error[2].empty() )
        std::cout << error[2] << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << numf  << 'f' << std::endl;

    std::cout << "double: ";
    if( !error[3].empty() )
        std::cout << error[3] << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << numd  << std::endl;
    
}

void    ScalarConverter::convert(std::string& literal)
{
    if (ConvertToPseudo(literal))
        return ;

    std::string error[4];
    char    c;
    int     num;
    float   numf;
    double  numd;


    try {
        c  = ConvertToCHAR(literal);
    }
    catch (std::exception& e) {
        error[0] = e.what();
    }

    try {
        num  = ConvertToINT(literal);
    }
    catch (std::exception& e) {
        error[1] = e.what();
    }


    try {
        numf  = ConvertToFLOAT(literal);
    }
    catch (std::exception& e) {
        error[2] = e.what();
    }

    try {
        numd  = ConvertToDOUBLE(literal);
    }
    catch (std::exception& e) {
        error[3] = e.what();
    }

    PrintToOutput(c, num, numf, numd, error);
}
