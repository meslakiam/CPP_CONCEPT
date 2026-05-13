#include "RPN.hpp"

Token::Token() : type(""), Operator(""), Number(0) {};

RPN::RPN() {} 

RPN::RPN(string l_inputs) : _inputString(l_inputs) {}
   
RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _l_tokens           = other._l_tokens;
        _s_calculationStack = other._s_calculationStack;
        _resulte            = other._resulte;
        _inputString        = other._inputString;
    }
    return *this;
}

RPN::~RPN() {}

string RPN::printError(string errorMsg, string errorValue , string errorMsg2 )
{
    string  str;

    str = errorMsg;
    if (!errorValue.empty())
        str += " " + errorValue ;
    if (!errorMsg2.empty())
        str += " " + errorMsg2;

    return str;
} 

Token RPN::identifyToken(string& token)
{
    Token tokenInfo;
    char *end;

    long  num = strtol(token.c_str(), &end, 10);

    if ( *end != '\0' && token.size() == 1 )
    {
        tokenInfo.type = "operator";
        tokenInfo.Operator = token;
    }
    else if (*end != '\0' && token.size() != 1)
        throw std::runtime_error(printError("Error:\n   ", token, "not a valid token"));
    else if (num < 10 &&  num > -2147483648)
    {
        tokenInfo.type = "digit";
        tokenInfo.Number = num;
    }
    else
        throw std::runtime_error(printError("Error:\n   ", token, "not a valid token"));

    return (tokenInfo);
}

long RPN::calculate(long& num1, long& num2, string& op)
{
    long res = 0;
    if ( op == "+")
        res = num1 + num2;
    else if ( op == "-")
        res = num1 - num2;
    else if ( op == "*")
        res = num1 * num2;
    else if ( op == "/")
        res = num1 / num2;
    else
        throw   std::runtime_error(printError("Error:\n   invalid operator", op));

    return (res);
}

List    RPN::splitTokens(string& s)
{
    std::istringstream str(s);
    string word;

    while (str >> word)
        _l_tokens.push_back(word);

    return _l_tokens; 
}

long    RPN::evaluateRPN()
{
    return ( evaluateRPN(_inputString) );
}

long    RPN::evaluateRPN(string inputs)
{
    _inputString = inputs;
    _l_tokens = splitTokens(_inputString);
    
    for ( List::iterator it = _l_tokens.begin(); it != _l_tokens.end(); it++)
    {
        Token t_currentToken = identifyToken(*it);
    
        if ( t_currentToken.type == "digit" )
            _s_calculationStack.push(t_currentToken.Number);
    
        else if ( t_currentToken.type == "operator" )
        {
            if ( _s_calculationStack.empty())
                throw   std::runtime_error(printError("Error:\n   bad input"));
    
            long num2 = _s_calculationStack.top();
            _s_calculationStack.pop();
    
            if ( _s_calculationStack.empty())
                throw   std::runtime_error(printError("Error:\n   bad input"));
        
            long num1 = _s_calculationStack.top();
            _s_calculationStack.pop();
     

            _resulte = calculate(num1, num2, t_currentToken.Operator);
            _s_calculationStack.push(_resulte);
        }
    }

    if ( _s_calculationStack.empty())
        throw   std::runtime_error(printError("Error:\n   bad input"));

    _resulte = _s_calculationStack.top();
    _s_calculationStack.pop();

    if ( !_s_calculationStack.empty())
        throw   std::runtime_error(printError("Error:\n   bad input"));

    return ( _resulte );
}

long&   RPN::getResulte() { return (_resulte); }