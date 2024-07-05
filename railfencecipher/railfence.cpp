#include <string>
#include <vector>

std::string encode_rail_fence_cipher(const std::string &str, int n) {
    if (n <= 1)
        return str;  // No change needed if only one rail or less

    std::vector<std::string> rails(n);
    int rail = 0;
    bool goingDown = false;

    for (char c : str) {
        rails[rail] += c;

        if (rail == 0 || rail == n - 1)
            goingDown = !goingDown;

        rail += goingDown ? 1 : -1;
    }

    std::string encoded_string;
    for (const std::string &railStr : rails) {
        encoded_string += railStr;
    }

    return encoded_string;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    if (n <= 1)
        return str;  // No change needed if only one rail or less

    std::vector<std::string> rails(n);
    std::vector<int> rail_lengths(n, 0);

    int rail = 0;
    bool goingDown = false;

    // Fill the rail matrix with placeholders
    for (char c : str) {
        rails[rail] += '*';  // Use a placeholder character
        if (rail == 0 || rail == n - 1)
            goingDown = !goingDown;
        rail += goingDown ? 1 : -1;
    }

    // Replace placeholders with actual characters
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < rails[i].size(); ++j) {
            rails[i][j] = str[index++];
        }
    }

    // Read the decoded message from the matrix
    std::string decoded_string;
    rail = 0;
    goingDown = false;
    for (int i = 0; i < str.size(); ++i) {
        decoded_string += rails[rail][rail_lengths[rail]++];
        if (rail == 0 || rail == n - 1)
            goingDown = !goingDown;
        rail += goingDown ? 1 : -1;
    }

    return decoded_string;
}