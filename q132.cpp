class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<bool>> valid(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) valid[i][i] = true;
        for (int i = 1; i < len; ++i) valid[i - 1][i] = s[i - 1] == s[i];
        for (int k = 2; k < len; ++k) {
            for (int i = 0; i + k < len; ++i) {
                valid[i][i + k] = valid[i + 1][i + k - 1] && (s[i] == s[i + k]);
            }
        }
        vector<int> dp(len + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = i; j > 0; --j) {
                if (valid[j - 1][i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len] - 1;
    }
};