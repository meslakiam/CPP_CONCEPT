#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <stack>

typedef std::string string;
typedef std::list<string>  List;
typedef std::stack<long> Stack;

struct Token
{
    string type;
    string Operator;
    int Number;
    Token();
};


class RPN {

    List    _l_tokens;
    Stack   _s_calculationStack;
    long    _resulte;
    string  _inputString;

    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    string  printError(string errorMsg, string errorValue = "" , string errorMsg2 = "" );
    List    splitTokens(string& s);
    Token   identifyToken(string& token);
    long    calculate(long& num1, long& num2, string& op);
    
    public:
        RPN();
        RPN(string input);
        ~RPN();

        long    evaluateRPN(string input);
        long    evaluateRPN();
        long&    getResulte();

};

#endif