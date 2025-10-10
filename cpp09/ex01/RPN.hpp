#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <stack>

class RPN
{
    private:
        std::stack<int> Stack;
    public:
        RPN();
        RPN(const RPN &copy);
        std::stack<int> getter();
        void setter(std::stack<int> S);
        RPN &operator=(const RPN &op);
        ~RPN();
};


#endif