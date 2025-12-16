#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP 

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

typedef enum Type {

    Char,
    Int,
    Float,
    Double,
    Pseudo,
    Invalid
} Type;

class   ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter& other);
        ScalarConverter&    operator=(ScalarConverter& other);
        ~ScalarConverter();

        static Type     GetOrigineType(std::string& literal);
        static void     InvalideType();

        static bool     IsChar(std::string& literal);
        static bool     IsInt(std::string& literal);
        static bool     IsFloat(std::string& literal);
        static bool     IsDouble(std::string& literal);

        static bool         CheckChar(long long c);
        static bool         CheckInt(long long num);
        static bool         CheckFloat(double numf);
        static bool         CheckDouble(double numd);

        static void         ConvertToCHAR(std::string& literal);
        static void         ConvertToINT(std::string& literal);
        static void         ConvertToFLOAT(std::string& literal);
        static void         ConvertToDOUBLE(std::string& literal);
        static bool         ConvertToPseudo(std::string& literal);

    public:

        static void convert(std::string& literal);

};

#endif