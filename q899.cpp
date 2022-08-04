class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for (int i = 0; i < s.length(); ++i) {
            string temp = s.substr(1);
            temp.push_back(s[0]);
            if (temp < res) res = temp;
            s = temp;
        }
        return res;
    }
};