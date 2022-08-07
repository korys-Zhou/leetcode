class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int len = edges.size();
        vector<bool> visited(len, false);
        int res = -1;
        for (int i = 0; i < len; ++i) {
            if (visited[i]) continue;
            int cur = i;
            vector<int> loop;
            while (cur >= 0 && !visited[cur]) {
                visited[cur] = true;
                loop.emplace_back(cur);
                cur = edges[cur];
            }
            for (int i = 0; i < loop.size(); ++i) {
                if (loop[i] == cur) {
                    res = max(res, (int)loop.size() - i);
                    break;
                }
            }
        }
        return res;
    }
};