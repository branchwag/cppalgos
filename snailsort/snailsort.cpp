#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<int> result;
    int n = snail_map.size();
    
    if (n == 0 || snail_map[0].size() == 0) {
        return result; // Return an empty vector for a 0x0 matrix
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(snail_map[top][i]);
        }
        top++;

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(snail_map[i][right]);
        }
        right--;

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; --i) {
                result.push_back(snail_map[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                result.push_back(snail_map[i][left]);
            }
            left++;
        }
    }

    return result;
}
