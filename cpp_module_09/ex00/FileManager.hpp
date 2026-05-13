#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

typedef std::string string;

struct LineResult {
    bool        found;
    string      date;
    string      priceStr;
    float       price;
    LineResult();
};

class fmanager {

    std::ifstream   _file;
    char            _del;
    static bool     _s_first_time;

    float       parseLine(string& date,string& value);
    void        validateDate(string& date);
    float       validateValue(string& value);
    void        validateLeepDay(long year, long day, string dayStr);
    bool        ReadLine( string& date, string& value );

    void        trim(string& s);

    fmanager(fmanager& other);
    fmanager&   operator=(fmanager& other);

    public:
        fmanager();
        ~fmanager();

        void openFile(string fileName);
        LineResult getNextLine( char del );
        static string printError(string errorMsg, string errorValue = "", string errorMsg2 = "");
        void closeFile();
};

#endif