#include "BitcoinExchange.hpp"

fmanager::fmanager() {}

void     fmanager::openFile(std::string fileName)
{
    std::ifstream f(fileName);

    if ( !f.is_open())
        throw std::runtime_error("cannot open file");

   this->_file = &f;
}

void    fmanager::validateLeepDay(long year, long month, long day)
{ 
    int maxDays = 28;

    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            maxDays = 29;
        }
    }

    if (day > maxDays) 
        throw std::runtime_error("Error in Date:\n  day not exist in February  !!");

}

void    fmanager::validateDate(std::string& date)    
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error in Date:\n  Invalid Date !!");

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    char *end;
    
    long year = std::strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0' || year < 2008)
        throw std::runtime_error("Error in Date:\n  Invalid year !!");

    long month = std::strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
        throw std::runtime_error("Error in Date:\n  Invalid month !!");

    long day = std::strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0' || day < 1 || day > 31)
        throw std::runtime_error("Error in Date:\n  Invalid day !!");

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("Error in Date:\n  day not exist in this month !!");

    if ( month == 2 )
        validateLeepDay(year, month, day);

}

void    fmanager::validateValue(std::string& value)    
{

}

std::pair<std::string, float>    fmanager::parseLine(std::string& date,std::string& value)
{
    validateDate(date);
    validateValue(value);
    
}

std::pair<std::string, float>   fmanager::getNextLine()
{
    std::string date;
    std::string value;
    if (std::getline(*_file, date, ','))
    {
        if (std::getline(*_file, value))
            return parseLine(date, value);
    }
    throw std::runtime_error("cannot read from file");
}



btc::btc(const std::string& fileName) : _fileName(fileName)
{
    fmanager dataBase;
    dataBase.openFile("data.csv");

}

