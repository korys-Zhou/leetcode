class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int res = 0, len = grades.size(), cur = 1;
        while (len >= cur) {
            len -= cur++;
            ++res;
        }
        return res;
    }
};