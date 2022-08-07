class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> stk;
        vector<int> res(n, 0);
        int time = 0;
        for (string& s : logs) {
            int id = -1, t = -1;
            bool start;
            string cur;
            for (char& ch : s) {
                if (ch == ':') {
                    if (id == -1) id = stoi(cur);
                    else start = cur == "start";
                    cur = "";
                }
                else cur.push_back(ch);
            }
            t = stoi(cur);
            if (start) {
                if (!stk.empty()) res[stk.top()] += t - time;
                stk.emplace(id);
                time = t;
            }
            else {
                res[stk.top()] += t - time + 1;
                stk.pop();
                time = t + 1;
            }
        }
        return res;
    }
};