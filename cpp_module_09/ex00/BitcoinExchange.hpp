#ifndef BITCOIEXCHANGE_HPP
#define BITCOIEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>

class fmanager {

    std::ifstream *_file;
    std::pair<std::string, float>    parseLine(std::string& date,std::string& value);
    void        validateDate(std::string& date);
    void        validateValue(std::string& value);
    void        validateLeepDay(long year, long month, long day);
    public:
        fmanager();
        void openFile(std::string fileName);
        std::pair<std::string, float> getNextLine();
};

class btc {

    private:
        std::map<std::string,float> _map;
        fmanager    _inputFile;
        const std::string& _fileName;



    public:
        btc(const std::string& file);
        // btc();


};

#endif