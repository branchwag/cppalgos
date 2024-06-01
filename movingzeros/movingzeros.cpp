#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> result;
    int zero_count = 0;

    for (const int& num : input) {
        if (num != 0) {
            result.push_back(num);
        } else {
            ++zero_count;
        }
    }

    result.insert(result.end(), zero_count, 0);

    return result;
}