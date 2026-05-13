#include "FileManager.hpp"

bool fmanager::_s_first_time = true;

LineResult::LineResult() : found(false), date(""), priceStr(""), price(0.0f) {}

fmanager::fmanager() : _file() { _s_first_time = true; }

fmanager::fmanager(fmanager& other) : _file()
{
    *this = other;
    _s_first_time = true;
}

fmanager& fmanager::operator=(fmanager& other) {
    (void)other;
    if (this != &other)
    {
        closeFile();
    }
    return *this;
}

fmanager::~fmanager()
{
    closeFile();
}
void fmanager::trim(std::string& s) {
    const std::string whitespace = " \t\n\r\f\v";

    size_t start = s.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        s = "";
        return;
    }

    size_t end = s.find_last_not_of(whitespace);

    s = s.substr(start, end - start + 1);
}

string fmanager::printError(string errorMsg, string errorValue , string errorMsg2 )
{
    string  str;

    str = errorMsg;
    if (!errorValue.empty())
        str += ": " + errorValue ;
    if (!errorMsg2.empty())
        str += " " + errorMsg2;

    return str;
} 
void     fmanager::openFile(std::string fileName)
{
    if (_file.is_open())
        _file.close();
    
    _file.open(fileName.c_str());
    if (!_file.is_open())
        throw std::runtime_error(printError("cannot open file", fileName));
}

void    fmanager::validateLeepDay(long year, long day, string dayStr)
{ 
    int maxDays = 28;

    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            maxDays = 29;
        }
    }

    if (day > maxDays) 
        throw std::runtime_error(printError("Error in Date", dayStr, "does not exist in this month."));

}

void    fmanager::validateDate(std::string& date)    
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error(printError("Error in Date", date, "bad input."));

    string yearStr = date.substr(0, 4);
    string monthStr = date.substr(5, 2);
    string dayStr = date.substr(8, 2);

    char *end;
    long year = std::strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0' || year < 2008 || year > 2147483647)
        throw std::runtime_error(printError("Error in Date", yearStr, "not a valid year."));

    long month = std::strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
        throw std::runtime_error(printError("Error in Date", monthStr, "not a valid month."));

    long day = std::strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0' || day < 1 || day > 31)
        throw std::runtime_error(printError("Error in Date", dayStr, "not a valid day."));

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error(printError("Error in Date", dayStr, "does not exist in this month."));

    if ( month == 2 )
        validateLeepDay(year, day, dayStr);

}

float    fmanager::validateValue(std::string& value)    
{
    char *end;
    float n = std::strtof(value.c_str(), &end);
    if ( *end != '\0' )
        throw std::runtime_error(printError("Error in value", value, "not a valid number."));
    if ( n < 0 )
        throw std::runtime_error(printError("Error in value", value, " not a positive number."));
    return ( n );
}

float fmanager::parseLine(std::string& date,std::string& value)
{
    trim(date);
    trim(value);

    validateDate(date);

    if ( value.empty() )
        throw std::runtime_error(printError("Error in value: there is no value at date ", date, "."));

    float num = validateValue(value);

    return ( num );
}

bool    fmanager::ReadLine(string& date, string& value)
{
    string      line;
    if (std::getline(_file, line))
    {
        size_t pos = line.find(_del);
        
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 1);
            return true;
        }
        else
            throw std::runtime_error(printError("Error in value: there is no value at date ", line, "."));
    }
    return false;
}
LineResult  fmanager::getNextLine( char del )
{
    string      date;
    string      value;
    LineResult  res;

    _del = del;
    if (_s_first_time)
    {
        _s_first_time = false;
        std::getline(_file, value);
    }

    if (ReadLine(date, value))
    {
        res.price = parseLine(date, value);
        res.priceStr = value;
        res.date = date;
        res.found = true;

        return res;
    }
    res.price = 0;
    return res;
}

void    fmanager::closeFile()
{
    if (this->_file.is_open())
    {
        this->_file.close();
    }
}
