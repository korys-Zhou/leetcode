class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cur = -1, res = 1;
        for (int i : nums) {
            cur += i;
            if (cur < 0) res = max(res, -cur);
        }
        return res;
    }
};