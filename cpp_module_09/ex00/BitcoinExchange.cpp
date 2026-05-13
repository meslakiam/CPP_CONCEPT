#include "BitcoinExchange.hpp"

btc::btc()
{
    fillDataBase();
}

btc::btc( string& fileName ) : _fileName(fileName)
{
    fillDataBase();

    runExchange();
}

btc::btc(btc& other) : _fileName(other.getFileName())
{
    *this = other;
}

btc&      btc::operator=( btc& other)
{
    if (this == &other)
        return *this;
    
    this->_m_dataBase = other.getDB();
    this->_fileName = other.getFileName();
    this->_m_inputData = other.getInputData();

    return *this;
}

btc::~btc() {}

void    btc::runExchange()
{
    runExchange(_fileName);
}

void    btc::runExchange(string& fileName)
{
    fmanager file;
    _fileName = fileName;

    file.openFile(_fileName);
    while (true)
    {
        try
        {
            LineResult res = file.getNextLine('|');
            if ( !res.found)
                break;
            if ( res.price < 0 || res.price > 1000 )
                throw std::runtime_error(fmanager::printError( "Error in value", res.priceStr, "too large a number."));
            calculePrice(res);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void    btc::fillDataBase()
{
    fmanager f_DB;
    f_DB.openFile("data.csv");

    while (true)
    {
        LineResult res = f_DB.getNextLine(',');
        if ( !res.found)
            break;
        _m_dataBase[res.date] = res.price;
    }
}

void    printResute(LineResult res, float resulte)
{
    std::cout << res.date << " ==> " << res.price << " = " << resulte << std::endl ;
}

void    btc::calculePrice(LineResult res)
{
    Map::iterator it_DB = _m_dataBase.upper_bound(res.date);

    it_DB--;
    float result = res.price * it_DB->second;
    printResute(res, result);
}

Map         btc::getDB() { return (this->_m_dataBase); }
Map         btc::getInputData() { return (this->_m_inputData) ;};
string&     btc::getFileName() { return (this->_fileName); }
