class UnionFind {
public:
    UnionFind(int n) {
        group.resize(n);
        for (int i = 0; i < n; ++i) group[i] = i;
    }

    int find(int i) {
        return group[i] == i ? i : group[i] = find(group[i]);
    }

    void insert(int i, int j) {
        int ii = find(i), jj = find(j);
        int t = min(ii, jj);
        group[ii] = group[jj] = t;
    }

private:
    vector<int> group;
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        UnionFind uf(1e5 + 1);
        for (int i : nums) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    uf.insert(i, j);
                    uf.insert(i, i / j);
                }
            }
        }
        vector<int> cnt(1e5 + 1, 0);
        for (int i : nums) {
            ++cnt[uf.find(i)];
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};