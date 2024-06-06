#include <string>
#include <vector>
#include <algorithm>

std::string multiply_strings(const std::string &num1, const std::string &num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 -1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum/ 10;
        }
    }

    std::string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    return product.empty() ? "0" : product;
}

std::string factorial(int n) {
    if (n < 0) {
        return "";
    }
    if (n == 0) {
        return "1";
    }

    std::string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply_strings(result, std::to_string(i));
    }

    return result;
}