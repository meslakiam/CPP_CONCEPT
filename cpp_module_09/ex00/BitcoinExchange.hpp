#ifndef BITCOIEXCHANGE_HPP
#define BITCOIEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>

#include "FileManager.hpp"


typedef std::map<string,float> Map;

class btc {
    private:
        Map             _m_dataBase;
        Map             _m_inputData;
        fmanager        _inputFile;
        string          _fileName;

        void    fillDataBase();
        btc( btc& other );
        btc&  operator=( btc& other);

    public:
        btc();
        btc( string& file);
        
        ~btc();

        void    fillInputData();
        void    fillInputData(string& fileName);

        void    calculePrice(LineResult res);

        Map getDB();
        string& getFileName();
        Map getInputData();
};

#endif