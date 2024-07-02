#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

// Helper function to subtract two large numbers represented as strings
std::string subtract_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int n = a.size();
    int m = b.size();
    int diff = n - m;

    for (int i = m - 1; i >= 0; --i) {
        int sub = ((a[i + diff] - '0') - (b[i] - '0') - carry);
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    for (int i = diff - 1; i >= 0; --i) {
        if (a[i] == '0' && carry) {
            result.push_back('9');
            continue;
        }
        int sub = ((a[i] - '0') - carry);
        if (i > 0 || sub > 0) { // remove leading zeros
            result.push_back(sub + '0');
        }
        carry = 0;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// Function to perform long division on strings representing large numbers
auto divide_strings(const std::string& a, const std::string& b) -> std::pair<std::string, std::string> {
    if (b == "0") {
        throw std::invalid_argument("Division by zero");
    }
    
    std::string quotient;
    std::string remainder;

    // Initialize remainder with the numerator
    remainder = "0";

    // Process each digit of the numerator
    for (char digit : a) {
        // Append the current digit to the remainder
        remainder += digit;

        // Remove leading zeros from the remainder
        remainder.erase(0, remainder.find_first_not_of('0'));
        if (remainder.empty()) {
            remainder = "0";
        }

        // Find the maximum number of times denominator can fit into the current remainder
        int count = 0;
        while (remainder.size() > b.size() || (remainder.size() == b.size() && remainder >= b)) {
            remainder = subtract_strings(remainder, b);
            ++count;
        }

        // Append the count to the quotient
        quotient += (char)('0' + count);
    }

    // Remove leading zeros from the quotient
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty()) {
        quotient = "0";
    }

    // Remove leading zeros from the remainder
    remainder.erase(0, remainder.find_first_not_of('0'));
    if (remainder.empty()) {
        remainder = "0";
    }

    // Return the quotient and remainder as a pair of strings
    return { quotient, remainder };
}