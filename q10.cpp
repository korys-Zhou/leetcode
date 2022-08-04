class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length(), lenp = p.length();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
        dp[0][0] = true;
        for (int i = 2; i <= lenp; i += 2) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else break;
        }
        for (int i = 1; i <= lens; ++i) {
            for (int j = 1; j <= lenp; ++j) {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    if (j > 1) dp[i][j] = dp[i][j] || dp[i][j - 2];
                }
            }
        }
        return dp[lens][lenp];
    }
};