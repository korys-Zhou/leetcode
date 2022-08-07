class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set({ nums.begin(),nums.end() });
        return set.size() - (set.count(0));
    }
};