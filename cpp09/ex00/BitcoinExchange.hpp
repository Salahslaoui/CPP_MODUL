#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include <map>

class Bitcoinexchange
{
    private:
        std::vector<std::string> data;
        std::map<std::string, double> B;
        Bitcoinexchange &operator=(const Bitcoinexchange &op);
    public:
        Bitcoinexchange();
        Bitcoinexchange(const Bitcoinexchange &copy);
        std::vector<std::string> get_data();
        std::map<std::string, double> getter_map();
        void setter_map(std::map<std::string, double> tmp);
        ~Bitcoinexchange();
};


#endif