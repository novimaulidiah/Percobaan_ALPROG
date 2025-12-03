#include "formatter.h"
#include <iomanip>

std::string formatNumber(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(0);

    std::string s = std::to_string((long long)value);
    int count = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        ss << s[s.size() - 1 - count];
        count++;
        if (count % 3 == 0 && i != 0) {
            ss << ",";
        }
    }

    std::string result = ss.str();
    std::reverse(result.begin(), result.end());
    return result;
}

void printSeparator() {
    std::cout << "===========================================================\n";
}
