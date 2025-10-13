#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    int prev = -1, curr;
    bool sorted = true;
    int line_num = 0;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string temp;
        char colon;
        iss >> temp >> temp >> temp >> colon >> curr;  // read "Pair", "x", "x", ":", "number"
        if (line_num > 0 && curr < prev) {
            std::cout << "❌ Not sorted at line " << line_num + 1
                      << ": " << prev << " > " << curr << std::endl;
            sorted = false;
            break;
        }
        prev = curr;
        line_num++;
    }

    if (sorted)
        std::cout << "✅ The list is sorted in ascending order.\n";

    return 0;
}