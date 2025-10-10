#include "BitcoinExchange.hpp"

Bitcoinexchange::Bitcoinexchange()
{}

Bitcoinexchange::Bitcoinexchange(const Bitcoinexchange &copy)
{
    (*this) = copy;
}

Bitcoinexchange &Bitcoinexchange::operator=(const Bitcoinexchange &op)
{
    (void)op;
    return *this;
}

std::map<std::string, double> Bitcoinexchange::getter_map()
{
    return B;
}

void Bitcoinexchange::setter_map(std::map<std::string, double> tmp)
{
    B = tmp;
}

std::vector<std::string> Bitcoinexchange::get_data()
{
    return data;
}

Bitcoinexchange::~Bitcoinexchange()
{}
