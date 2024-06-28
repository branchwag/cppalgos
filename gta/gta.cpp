#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

// Function to extract digits from a number and insert them into a set to ensure uniqueness
void extractDigits(int number, std::set<int>& uniqueDigits) {
    while (number > 0) {
        uniqueDigits.insert(number % 10);
        number /= 10;
    }
}

// Function to calculate the sum of all subsets of the base list up to a specified limit
void calculateSubsetsSums(const std::vector<int>& baseList, int limit, int& gtaValue) {
    int n = baseList.size();
    int totalSubsets = 1 << n; // 2^n subsets

    for (int subsetMask = 1; subsetMask < totalSubsets; ++subsetMask) {
        int currentSum = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (subsetMask & (1 << i)) {
                currentSum += baseList[i];
                ++count;
            }
        }
        if (count <= limit) {
            gtaValue += currentSum;
        }
    }
}

int gta(int limit, const std::vector<int>& args) {
    std::set<int> uniqueDigits;
    for (int number : args) {
        extractDigits(number, uniqueDigits);
    }
    
    // Convert the set to a vector to work with
    std::vector<int> baseList(uniqueDigits.begin(), uniqueDigits.end());
    
    // Limit the number of terms in the base list
    if (static_cast<int>(baseList.size()) > limit) {
        baseList.resize(limit);
    }

    int gtaValue = 0;
    calculateSubsetsSums(baseList, limit, gtaValue);

    return gtaValue;
}
