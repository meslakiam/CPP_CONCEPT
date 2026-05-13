#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <bits/stdc++.h>
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

    
    // RPN(string data);
    RPN(RPN& other);
    RPN& operator=(RPN& other);

    string  printError(string errorMsg, string errorValue = "" , string errorMsg2 = "" );
    Token   identifyToken(string& token);
    long    calculate(long& num1, long& num2, string& op);
    
    public:
        RPN();
        RPN(List l_inputs);
        ~RPN();

        long    evaluateRPN(List l_inputs);
        long    getResulte();

};
#endif