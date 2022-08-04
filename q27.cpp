class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] == val) {
                swap(nums[l], nums[r--]);
            }
            else ++l;
        }
        return nums[l] == val ? l : l + 1;
    }
};