class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        if (len == 0) return 0;
        vector<vector<int>> kmp(len, vector<int>(26, 0));
        kmp[0][needle[0] - 'a'] = 1;
        int pre = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < 26; ++j) {
                kmp[i][j] = kmp[pre][j];
            }
            kmp[i][needle[i] - 'a'] = i + 1;
            pre = kmp[pre][needle[i] - 'a'];
        }
        int cur = 0;
        for (int i = 0; i < haystack.length(); ++i) {
            if ((cur = kmp[cur][haystack[i] - 'a']) == len) return i - len + 1;
        }
        return -1;
    }
};