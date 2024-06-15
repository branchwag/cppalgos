#include <cstdint>
#include <vector>

using namespace std;

uint32_t partitions(uint32_t n) {
    vector<vector<uint32_t>> dp(n + 1, vector<uint32_t>(n+1, 0));
    dp[0][0] = 1;

    for (uint32_t i = 0; i <= n; ++i) {
        for (uint32_t j = 1; j <=n; ++j) {
            dp[i][j] = dp[i][j -1];
            if (i >= j) {
                dp[i][j] += dp[i -j][j];
            }
        }
    }
    return dp[n][n];
}