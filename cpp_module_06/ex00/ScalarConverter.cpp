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

bool      ScalarConverter::IsChar(std::string& literal)
{
    if ( literal.length() == 1 && !isdigit(literal[0]))
        return (  true );

    return ( false );
}

bool      ScalarConverter::IsInt(std::string& literal)
{
    int j = 0;
    if (literal[0] == '-' || literal[0] == '+')
        j++;
    for (size_t i = j; i < literal.length() ; i++)
    {
        if ( !isdigit(literal[i]))
            return ( false );
    }
    
    return ( true );
}

bool      ScalarConverter::IsFloat(std::string& literal)
{
    bool hasdot = false;

    int j = 0;

    if (literal[0] == '-' || literal[0] == '+')
        j++;

    for (size_t i = j; i < (literal.length() - 1) ; i++)
    {
        if ( hasdot == false && literal[i] == '.')
        {
            hasdot = true;
            continue;
        }
        if ( !isdigit(literal[i]))
            return ( false );
    }
    
    if ( literal[literal.length() - 1] != 'f' )
        return ( false );

    return ( true );
}

bool      ScalarConverter::IsDouble(std::string& literal)
{
    bool hasdot = false;

    int j = 0;

    if (literal[0] == '-' || literal[0] == '+')
        j++;

    for (size_t i = j; i < literal.length() ; i++)
    {
        if ( hasdot == false && literal[i] == '.')
        {
            hasdot = true;
            continue;
        }
        if ( !isdigit(literal[i]))
            return ( false );
    }

    return ( true );
}

bool    ScalarConverter::CheckChar( long long c)
{
     if (c < 0 || c > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return ( false );
    }

    unsigned char ch = static_cast<unsigned char>(c);

    if (!isprint(ch))
    {
        std::cout << "char: Non displayable" << std::endl;
        return ( false );
    }

    return ( true );
}

bool    ScalarConverter::CheckInt(long long num)
{
    if ( num > INT_MAX || num < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        return ( false );
    }
    return ( true );
}

bool    ScalarConverter::CheckFloat(double num)
{
    if (std::isnan(num))
    {
        std::cout << "float: nanf" << std::endl;
        return ( false );
    }

    else if (std::isinf(num))
    {
        if (num > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return ( false );
    }

    if ( std::fabs(num) > FLT_MAX )
    {
        std::cout << "float: impossible" << std::endl;
        return ( false );
    }

    return ( true );
}

bool    ScalarConverter::CheckDouble(double num)
{
    if (std::isnan(num))
        std::cout << "double: nan" << std::endl;

    else if (std::isinf(num))
    {
        if (num > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return ( false );
    }

        if ( std::fabs(num) > DBL_MAX )
    {
        std::cout << "Double: impossible" << std::endl;
        return ( false );
    }
    return ( true );
}

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

void    ScalarConverter::ConvertToCHAR(std::string& literal)
{
    char c = static_cast< char >(literal[0]);

    int i = static_cast< int >(c);
    float f = static_cast< float >(c);
    double d = static_cast< double >(c);

    std::cout << "char: " << c << std::endl ;
    std::cout << "int: " << i << std::endl ;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl ;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl ;
}

void    ScalarConverter::ConvertToINT(std::string& literal)
{
    long long num = atoll(literal.c_str());
    
    char c = static_cast< char >(num);
    float f = static_cast< float >(num);
    double d = static_cast< double >(num);

    if (CheckChar(num))
        std::cout << "char: " << c << std::endl;

    if ( CheckInt(num))
        std::cout << "int: " << static_cast< int >(num) << std::endl;

    if ( CheckFloat(d))
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;

    if ( CheckDouble(d))
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void    ScalarConverter::ConvertToFLOAT(std::string& literal)
{
    double f = std::strtod(literal.c_str(), 0);
    
    char c = static_cast< char >(f);
    long long num = static_cast< long long >(f);
    double d = static_cast< double >(f);

    if (!std::isnan(f) && !std::isinf(f))
    {
        if (CheckChar(num))
            std::cout << "char: " << c << std::endl;

        if ( CheckInt(num))
            std::cout << "int: " << static_cast< int >(num) << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    if ( CheckFloat(f))
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast< float >(f) << 'f' << std::endl;

    if ( CheckDouble(d))
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void    ScalarConverter::ConvertToDOUBLE(std::string& literal)
{
    double d = std::strtod(literal.c_str(), 0);
    
    char c = static_cast< char >(d);
    long long num = static_cast< long long >(d);
    float f = static_cast< float >(d);

    if (!std::isnan(f) && !std::isinf(f))
    {
        if (CheckChar(num))
            std::cout << "char: " << c << std::endl;

        if ( CheckInt(num))
            std::cout << "int: " << static_cast< int >(num) << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    if ( CheckFloat(d))
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;

    if ( CheckDouble(d))
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void     ScalarConverter::InvalideType()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

Type    ScalarConverter::GetOrigineType(std::string& literal)
{
    if ( IsChar(literal) )
        return ( Char );

    if ( IsInt(literal) )
        return ( Int );

    if ( IsFloat(literal) )
        return ( Float );

    if ( IsDouble(literal) )
        return ( Double );

    return ( Invalid );
}

void    ScalarConverter::convert(std::string& literal)
{
    Type type;

    if ( ConvertToPseudo( literal ))
        return ;

    if ( literal.empty() )
        type = Invalid;
    else
        type = GetOrigineType(literal);

    switch (type)
    {
        case Char:
            ConvertToCHAR(literal);
            break;

        case Int:
            ConvertToINT(literal);
            break;

        case Float:
            ConvertToFLOAT(literal);
            break;

        case Double:
            ConvertToDOUBLE(literal);
            break;

        default:
            InvalideType();
            break;
    }

}
