#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> result;
    
    for(int i = 0; i < s.length(); i+=2) {
        if (i + 1 < s.length()) {
            result.push_back(s.substr(i,2));
        } else {
            result.push_back(s.substr(i,1)+ "_");
        }
    }
    return result;
}
int main() {
    std::string input = "abcdefghi";
    std::vector<std::string> result = solution(input);
    
    for (const std::string& pair : result) {
        std::cout << pair << " ";
    }
    
    return 0;
}