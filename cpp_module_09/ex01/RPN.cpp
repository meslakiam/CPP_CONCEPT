#include "RPN.hpp"

Token::Token() : type(""), Operator(""), Number(0) {};

RPN::RPN() {} 

RPN::RPN(List l_inputs) : _l_tokens(l_inputs) {}
   
RPN::RPN(RPN& other) {(void)other;}

RPN&     RPN::operator=(RPN& other) {(void)other; return *this;}

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

        // std::cout << "token_num = " << token << std::endl;

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
        // std::cout << "num = " << num << std::endl;

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
long    RPN::evaluateRPN(List l_inputs)
{
    _l_tokens = l_inputs;

    for ( List::iterator it = _l_tokens.begin(); it != _l_tokens.end(); it++)
    {
        Token t_currentToken = identifyToken(*it);
        if ( t_currentToken.type == "digit" )
        {
            _s_calculationStack.push(t_currentToken.Number);
            // std::cout << "num = " << t_currentToken.Number << std::endl;

        }
        else if ( t_currentToken.type == "operator" )
        {
            long num2 = _s_calculationStack.top();
            _s_calculationStack.pop();

            long num1 = _s_calculationStack.top();
            _s_calculationStack.pop();
     
            // std::cout << "num1 = " << num1 << "num2 = " << num2 << std::endl;

            _resulte = calculate(num1, num2, t_currentToken.Operator);
            _s_calculationStack.push(_resulte);
        }
    }

    _resulte = _s_calculationStack.top();
    _s_calculationStack.pop();

    if ( !_s_calculationStack.empty())
        throw   std::runtime_error(printError("Error:\n   bad input"));

    return _resulte;
}


long RPN::getResulte() { return (_resulte); }