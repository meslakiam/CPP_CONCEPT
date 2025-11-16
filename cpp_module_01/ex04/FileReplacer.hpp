#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class   FileReplacer{

    private:
        std::string _fileName;
        std::string _inData;
        std::string _outData;

    public:
        FileReplacer(std::string FileName);
        bool            Open();
        void            Replace(std::string s1, std::string s2);
        bool            WriteToFile();

};

#endif