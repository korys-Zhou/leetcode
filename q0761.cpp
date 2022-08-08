class Solution {
public:
    string makeLargestSpecial(string s) {
        return helper(s, 0, s.length());
    }

private:
    string helper(string& s, int l, int r) {
        int len = r - l, cur = 0;
        vector<int> level(len);
        for (int i = l; i < r; ++i) {
            if (s[i] == '1') ++cur;
            else --cur;
            level[i - l] = cur;
        }
        int t = 100;
        for (int i = 1; i < len - 1; ++i) {
            if (level[i] < level[i - 1] && level[i] < level[i + 1]) {
                t = min(t, level[i]);
            }
        }
        if (t == 100) return s.substr(l, r - l);
        vector<int> subs;
        string ret;
        if (t == 0) subs.emplace_back(l - 1);
        for (int i = 0; i < len; ++i) {
            if (level[i] == t) subs.emplace_back(i + l);
        }
        ret += s.substr(l, subs[0] - l + 1);
        vector<string> ss;
        for (int i = 1; i < subs.size(); ++i) {
            ss.emplace_back(helper(s, subs[i - 1] + 1, subs[i] + 1));
        }
        sort(ss.rbegin(), ss.rend());
        for (string& sss : ss) {
            ret += sss;
        }
        ret += s.substr(subs.back() + 1, r - subs.back() - 1);
        return ret;
    }
};