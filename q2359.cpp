class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int len = edges.size();
        vector<int> dis1(len, -1), dis2(len, -1);
        int step = 0;
        queue<int> que;
        que.emplace(node1);
        while (!que.empty()) {
            for (int len = que.size(); len > 0; --len) {
                int cur = que.front(); que.pop();
                if (dis1[cur] >= 0) continue;
                dis1[cur] = step;
                if (edges[cur] >= 0) que.emplace(edges[cur]);
            }
            ++step;
        }
        step = 0;
        que.emplace(node2);
        while (!que.empty()) {
            for (int len = que.size(); len > 0; --len) {
                int cur = que.front(); que.pop();
                if (dis2[cur] >= 0) continue;
                dis2[cur] = step;
                if (edges[cur] >= 0) que.emplace(edges[cur]);
            }
            ++step;
        }
        int res_val = INT_MAX, res = -1;
        for (int i = 0; i < len; ++i) {
            if (dis1[i] < 0 || dis2[i] < 0) continue;
            int local = max(dis1[i], dis2[i]);
            if (local < res_val) {
                res_val = local;
                res = i;
            }
        }
        return res;
    }
};