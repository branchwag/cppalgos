#include<iostream>
#include<string>

using namespace std;

// Helper function to expand around a center
int expand_around_center(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return right - left - 1;
}

// Function to find longest palindromic substring
string longest_palindrome(const string &s) {
    if (s.empty()) return "";

    int start = 0, end = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        // Single character center
        int len1 = expand_around_center(s, i, i);
        // Two characters center
        int len2 = expand_around_center(s, i, i + 1);

        int len = max(len1, len2);

        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}