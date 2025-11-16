#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string FileName)
{
    _fileName = FileName;
}

bool  FileReplacer::FileReplacer::Open( void )
{
    std::ifstream InFile(_fileName.c_str());
    if(!InFile.is_open())
        return (false);
    std::ostringstream StoreData;
    StoreData << InFile.rdbuf();
    _inData = StoreData.str();
    return (true);
}

void    FileReplacer::Replace(std::string s1, std::string s2)
{
    size_t  Pos;

    _outData = _inData;
    while ((Pos = _outData.find(s1)) != std::string::npos)
    {
        std::string NewSTR = _outData.erase(Pos, s1.length());
        _outData = NewSTR.insert(Pos, s2);
    }
}

bool            FileReplacer::WriteToFile( void )
{
    std::ofstream    OutFile(_fileName.append(".replace").c_str());
    if(!OutFile.is_open())
        return (false);
    OutFile << _outData ;
    return (true);
}
