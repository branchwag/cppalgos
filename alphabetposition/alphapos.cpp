#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cctype>
#include <vector>
#include <sstream>

std::string alphabet_position(const std::string &text) {
    std::map<char, int> alphanum;
    for (char c = 'a'; c <= 'z'; ++c) {
        alphanum[c] = c - 'a' + 1;
    }

    std::vector<std::string> result;

    for (char ch : text) {
        char lowerch = std::tolower(ch);
        auto it = alphanum.find(lowerch);
        if (it != alphanum.end()) {
            result.push_back(std::to_string(it->second));
        }
    }

    std::ostringstream oss;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) {
            oss << " ";
        }
        oss << result[i];
    }

    return oss.str();
}


int main() {
    std::cout << alphabet_position("The sunset sets at twelve o'clock.") << std::endl;
    return 0;
}
