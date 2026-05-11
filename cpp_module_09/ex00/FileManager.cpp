#include "FileManager.hpp"

bool fmanager::_s_first_time = true;

LineResult::LineResult() : found(false), date(""), price(0.0f) {}

fmanager::fmanager() : _file() { _s_first_time = true; }

fmanager::fmanager(fmanager& other) : _file() {
    *this = other;
    _s_first_time = true;
}

fmanager& fmanager::operator=(fmanager& other) {
    (void)other;
    if (this != &other) {
        if (this->_file.is_open()) {
            this->_file.close();
        }
    }
    return *this;
}

fmanager::~fmanager() {
    if (this->_file.is_open()) {
        this->_file.close();
    }
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

void     fmanager::openFile(std::string fileName)
{
    if (_file.is_open())
        _file.close();
    
    _file.open(fileName.c_str());
    if (!_file.is_open())
        throw std::runtime_error("cannot open file");
}

void    fmanager::validateLeepDay(long year, long day)
{ 
    int maxDays = 28;

    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            maxDays = 29;
        }
    }

    if (day > maxDays) 
        throw std::runtime_error("Error in Date:  day not exist in February  !!");

}

void    fmanager::validateDate(std::string& date)    
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error in Date:  Invalid Date !!");

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    char *end;
    long year = std::strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0' || year < 2008 || year > 2147483647)
        throw std::runtime_error("Error in Date:  Invalid year !!");

    long month = std::strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
        throw std::runtime_error("Error in Date:  Invalid month !!");

    long day = std::strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0' || day < 1 || day > 31)
        throw std::runtime_error("Error in Date:  Invalid day !!");

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("Error in Date:  day not exist in this month !!");

    if ( month == 2 )
        validateLeepDay(year, day);

}

float    fmanager::validateValue(std::string& value)    
{
    char *end;
    float n = std::strtof(value.c_str(), &end);
    if ( *end != '\0' || n < 0 )
        throw std::runtime_error("Error in value: value not a number !!");
    return ( n );
}

float fmanager::parseLine(std::string& date,std::string& value)
{
    trim(date);
    trim(value);
    validateDate(date);
    float num = validateValue(value);

    return ( num );
}

LineResult  fmanager::getNextLine(string first_arg, string second_arg, char del)
{
    std::string date;
    std::string value;
    LineResult res;

    if (_s_first_time)
    {
        string sec;
        _s_first_time = false;

        std::getline(_file, value, del);
        std::getline(_file, sec);
        trim(value);
        trim(sec);

        if ( value != first_arg)
            throw std::runtime_error("Error in first line !!");
        if ( sec != second_arg)
            throw std::runtime_error("Error in first line !!");
    }

    if (std::getline(_file, date, del))
    {
        if (std::getline(_file, value))
        {
            res.price = parseLine(date, value);
            res.date = date;
            res.found = true;
            return res;
        }
        throw std::runtime_error("Error in value: there is no value !!");
    }
    res.price = 0;
    return res;
}
