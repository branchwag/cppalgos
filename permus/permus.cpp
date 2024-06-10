#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> permutations(std::string s) {
    std::vector<std::string> result;
    std::sort(s.begin(), s.end());
    do {
        result.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return result;
}