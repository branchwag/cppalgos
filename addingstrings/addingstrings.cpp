#include <string>
#include <algorithm>

std::string add(const std::string& a, const std::string& b) {
    int maxLength = std::max(a.length(), b.length());
    
    std::string result = "";
    int carry = 0;

    for (int i = 0; i < maxLength; ++i) {
        int digitA = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
        int digitB = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;

        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}
