class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        n <<= 1;
        function<void(int, int)> dfs = [&](int i, int rank) {
            if (rank < 0) return;
            if (i == n) {
                if (rank == 0) res.emplace_back(cur);
                return;
            }
            cur.push_back('(');
            dfs(i + 1, rank + 1);
            cur.back() = ')';
            dfs(i + 1, rank - 1);
            cur.pop_back();
        };
        dfs(0, 0);
        return res;
    }
};