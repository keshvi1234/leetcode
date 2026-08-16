class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        size_t n = matrix.size(), m = matrix[0].size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        std::multiset<int> rbt;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                dp[i][j] = (matrix[i - 1][j - 1] ^ dp[i][j - 1] ^ dp[i - 1][j] ^ dp[i - 1][j - 1]);
                rbt.insert(dp[i][j]);
                if (rbt.size() > k) rbt.erase(rbt.begin());
            }
        }
        return *rbt.begin();
    }
};