#include "RPN.hpp"

void check_number(char *num, std::stack<int> &Stack)
{
    int tmp;
    int tmp1;

    for(size_t i = 0; num[i]; ++i)
    {
        if (num[i] == ' ' || num[i] == '\t')
            continue;
        if (!isdigit(num[i]) && num[i] != '+' && num[i] != '-' && num[i] != '*' && num[i] != '/')
            throw std::runtime_error("Error");
        if (num[i + 1] && isdigit(num[i]) && isdigit(num[i + 1]))
            throw std::runtime_error("Error");
        if (isdigit(num[i]))
        {
            Stack.push(num[i] - 48);
            continue;
        }
        if (num[i] == '-' || num[i] == '+' || num[i] == '*' || num[i] == '/')
        {
            if (Stack.size() < 2)
                throw std::runtime_error("Error");
            if (Stack.size() > 0)
            {
                tmp = Stack.top();
                Stack.pop();
            }
            if (Stack.size() > 0)
            {
                tmp1 = Stack.top();
                Stack.pop();
            }
            if (num[i] == '+')
                Stack.push(tmp1 + tmp);
            else if (num[i] == '-')
                Stack.push(tmp1 - tmp);
            else if (num[i] == '*')
                Stack.push(tmp1 * tmp);
            else if (num[i] == '/')
            {
                if (tmp == 0)
                    throw std::runtime_error("division by 0 impossible!!");
                Stack.push(tmp1 / tmp);
            }
        }
    }
}

int main(int ac, char **av)
{
    RPN stack;
    std::stack<int> S;
    if (ac != 2)
        return (std::cerr << "Enter the right arguments!!" << std::endl, 1);
    try
    {
        S = stack.getter();
        check_number(av[1], S);
        while (!S.empty())
        {
            std::cout << S.top() << " ";
            S.pop();
        }
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}