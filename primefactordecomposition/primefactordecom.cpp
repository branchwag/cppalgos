#include <iostream>
#include <string>
#include <map>
#include <cmath>

class PrimeDecomp {
public:
    static std::string factors(int lst){
        std::map<int, int> primeCounts;

        for (int i =2; i <= std::sqrt(lst); ++i) {
            while (lst % i == 0) {
                primeCounts[i]++;
                lst /= i;
            }
        }

        if (lst > 1) {
            primeCounts[lst]++;
        }

        std::string result;
        for (const auto& [prime, count] : primeCounts) {
            result += "(" + std::to_string(prime);
            if (count > 1) {
                result += "**" + std::to_string(count);
            }
            result += ")";
        }
        return result; 
    }
};