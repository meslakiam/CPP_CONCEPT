#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

typedef std::string string;

struct LineResult {
    bool        found;
    string date;
    float       price;
    LineResult();
};

class fmanager {

    std::ifstream _file;
    char del;
    static bool _s_first_time;

    float         parseLine(string& date,string& value);
    void        validateDate(string& date);
    float       validateValue(string& value);
    void        validateLeepDay(long year, long day);
    void        trim(string& s);

    fmanager(fmanager& other);
    fmanager&   operator=(fmanager& other);

    public:
        fmanager();
        ~fmanager();

        void openFile(string fileName);
        LineResult getNextLine(string first_arg, string second_arg, char del);
};

#endif