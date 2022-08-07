class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            if (helper(words, i)) res.emplace_back(words[i]);
        }
        return res;
    }

private:
    bool helper(vector<string>& words, int n) {
        string cur = words[n];
        int len = cur.length();
        vector<vector<int>> kmp(len, vector<int>(26, 0));
        kmp[0][cur[0] - 'a'] = 1;
        int pre = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < 26; ++j) {
                kmp[i][j] = kmp[pre][j];
            }
            kmp[i][cur[i] - 'a'] = i + 1;
            pre = kmp[pre][cur[i] - 'a'];
        }
        for (int i = 0; i < words.size(); ++i) {
            if (i == n) continue;
            int state = 0;
            for (char& ch : words[i]) {
                if ((state = kmp[state][ch - 'a']) == len) return true;
            }
        }
        return false;
    }
};