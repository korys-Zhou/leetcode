class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<bool> visited(len, false);
        function<void(int)> dfs = [&](int i) {
            if (i == len) {
                res.emplace_back(cur);
                return;
            }
            for (int ii = 0; ii < len; ++ii) {
                if (visited[ii]) continue;
                if (ii > 0 && nums[ii] == nums[ii - 1] && !visited[ii - 1]) continue;
                cur.emplace_back(nums[ii]);
                visited[ii] = true;
                dfs(i + 1);
                visited[ii] = false;
                cur.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};