#include <iostream>
#include <vector>

using namespace std;

// Function to get the cofactor of matrix 'm' by removing the specified row and column
vector<vector<long long>> getCofactor(vector<vector<long long>> m, int p, int q, int n) {
    int i = 0, j = 0;
    vector<vector<long long>> temp(n, vector<long long>(n));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copy only those elements which are not in the given row and column
            if (row != p && col != q) {
                temp[i][j++] = m[row][col];
                // Row is filled, so increase row index and reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    temp.resize(n - 1); // Resize temp to be (n-1) x (n-1)
    for (auto &row : temp) {
        row.resize(n - 1);
    }
    return temp;
}

// Recursive function to find the determinant of matrix 'm'
long long determinant(vector<vector<long long>> m, int n) {
    // Base case: if matrix contains single element
    if (n == 1)
        return m[0][0];

    // Base case: if matrix is 2x2
    if (n == 2)
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];

    long long det = 0; // Initialize result
    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++) {
        // Getting Cofactor of m[0][f]
        vector<vector<long long>> temp = getCofactor(m, 0, f, n);
        det += sign * m[0][f] * determinant(temp, n - 1);
        // Terms are to be added with alternate sign
        sign = -sign;
    }
    return det;
}

// Wrapper function for easier usage
long long determinant(vector<vector<long long>> m) {
    int n = m.size();
    return determinant(m, n);
}

