#include "BitcoinExchange.hpp"

std::map<std::string, double> get_map(std::ifstream &file)
{
    std::map<std::string, double> B;
    std::string line;
    std::getline(file, line);
    std::string date;
    std::string price_str;

    while (std::getline(file, line))
    {
        std::stringstream tmp(line);
        if (std::getline(tmp, date, ',') && std::getline(tmp, price_str))
        {
            double price = std::atof(price_str.c_str());
            B[date] = price;
        }
    }
    return B;
}

bool is_valid(std::string date)
{
    std::stringstream tmp(date);
    std::string year, month, day;

    if (!std::getline(tmp, year, '-') || !std::getline(tmp, month, '-') || !std::getline(tmp, day, '-'))
        return false;
    int year_i = std::atoi(year.c_str());
    int month_i = std::atoi(month.c_str());
    int day_i = std::atoi(day.c_str());
    struct tm timeinfo = {};
    timeinfo.tm_year = year_i - 1900;
    timeinfo.tm_mon = month_i - 1;
    timeinfo.tm_mday = day_i;
    time_t t = mktime(&timeinfo);
    if (t == -1)
        return false;
    return (timeinfo.tm_year == year_i - 1900 && timeinfo.tm_mon  == month_i - 1 &&
            timeinfo.tm_mday == day_i);
}

void check_date(std::string date, std::string price_str)
{
    int k = 0;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 10 && date[i] == ' ')
            continue;
        else if ((i == 4 || i == 7) && date[i] == '-')
            continue;
        else if (!isdigit(date[i]))
            throw std::runtime_error("the date is invalid numbers only!!!");
    }
    for (size_t i = 0; i < price_str.size(); ++i)
    {
        if (price_str[i] == ' ')
            continue;
        if (price_str[i] == '.')
            k++;
        if (k > 1)
            throw std::runtime_error("bad input");
        if (price_str[i] == '.' && price_str[i - 1] && isdigit(price_str[i - 1]))
            continue;
        if (price_str[i] == '-' && price_str[i + 1] && isdigit(price_str[i + 1]))
            continue;
        if (!isdigit(price_str[i]))
            throw std::runtime_error("bad input");
    }
    std::stringstream tmp(date);
    std::string year;
    std::string month;
    std::string day;
    std::getline(tmp, year, '-');
    std::getline(tmp, month, '-');
    std::getline(tmp, day, '-');
    if (std::atoi(year.c_str()) < 2001 || std::atoi(year.c_str()) > 2026)
        throw std::runtime_error("bad input");
    if (std::atoi(month.c_str()) > 12)
        throw std::runtime_error("bad input");
    if (!is_valid(date))
        throw std::runtime_error("bad input");
    // std::cout << date << " " << date.size() << std::endl;
    return ;
}

std::map<std::string, double> parse_input(std::ifstream &file, std::map<std::string, double> map)
{
    std::map<std::string, double> B;
    std::string line;
    std::string date;
    std::string price_str;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("The header is not correct check if u forgot the spaces in the end and it must be: date | value.");
    while (std::getline(file, line))
    {
        std::stringstream tmp(line);
        std::getline(tmp, date, '|');
        std::getline(tmp, price_str);
        try
        {
            check_date(date, price_str);
            double price = std::atof(price_str.c_str());
            if (price > 2147483647)
                throw std::runtime_error("too large a number.");
            if (price < 0)
                throw std::runtime_error("not a positive number.");
        std::map<std::string, double>::iterator it = map.lower_bound(date);
        if (it != map.end() && it->first == date)
        {
            std::cout << date << " ==> " << price_str << " = " << price * it->second << std::endl;
        }
        else
        {
            if (it == map.begin())
                throw std::runtime_error("No data found!!!");
            else
            {
                --it;
                std::cout << date << " ==>" << price_str << " = " << price * it->second << std::endl;  
            }
        }
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return B;
}

int main(int ac, char **av)
{
    Bitcoinexchange Btc;
    std::map<std::string, double> map;
    std::map<std::string, double> in;

    try
    {
        if (ac != 2)
        return (std::cerr << "Enter one argument!!" << std::endl, 1);
        std::ifstream inp(av[1]);
        if (!inp.is_open())
        return (std::cerr << "failed to open the file passed in arguments!!!" << std::endl, 1);
        std::ifstream file("data.csv");
        if (!file.is_open())
        {
            std::cerr << "Error could not open file!!" << std::endl;
            return 1;
        }
        Btc.setter_map(get_map(file));
        map = Btc.getter_map();
        in = parse_input(inp, map);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}