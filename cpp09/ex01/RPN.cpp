#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &copy)
{
    (void) copy;
}

std::stack<int> RPN::getter()
{
    return Stack;
}
void RPN::setter(std::stack<int> S)
{
    Stack = S;
}

RPN &RPN::operator=(const RPN &op)
{
    if (this != &op)
        Stack = op.Stack;
    return (*this);
}

RPN::~RPN()
{}