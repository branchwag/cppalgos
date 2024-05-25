#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::replace
#include <cctype>    // For std::toupper and std::tolower
using namespace std;

std::string to_camel_case(const std::string& str) {
    if (str.empty()) {
        return "";
    } else {
        std::vector<std::string> containmentArea;
        std::string modifiedStr = str;
        
        std::replace_if(modifiedStr.begin(), modifiedStr.end(), [](char c) {
            return !std::isalnum(c);
        }, '_');

        size_t pos = 0;
        while ((pos = modifiedStr.find('_')) != std::string::npos) {
            std::string word = modifiedStr.substr(0, pos);
            containmentArea.push_back(word);
            modifiedStr.erase(0, pos + 1);
        }
        containmentArea.push_back(modifiedStr);

        for (size_t i = 1; i < containmentArea.size(); ++i) {
            std::string& word = containmentArea[i];
            word[0] = std::toupper(word[0]);
        }

        std::string newSentence = "";
        for (const std::string& word : containmentArea) {
            newSentence += word;
        }

        return newSentence;
    }
}




int main() {
    cout << to_camel_case("the-stealth-warrior") << endl;
    return 0;
}