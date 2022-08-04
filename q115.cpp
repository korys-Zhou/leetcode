class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.length(), lent = t.length();
        vector<vector<unsigned long long>> dp(lens + 1, vector<unsigned long long>(lent + 1, 0));
        for (int i = 0; i <= lens; ++i) dp[i][0] = 1;
        for (int i = 1; i <= lens; ++i) {
            for (int j = 1; j <= lent; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[lens][lent];
    }
};