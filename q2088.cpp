class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] < 1) continue;
                int d = 1;
                if (j > 0) d = max(d, grid[i][j - 1] - 1);
                while (j + d < n && j - d >= 0 && grid[i][j + d]>0 && grid[i][j - d] > 0) ++d;
                grid[i][j] = d;
            }
        }
        vector<vector<int>> copy = grid;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] < 1) continue;
                int h = 1;
                if (i > 0) h = max(h, grid[i - 1][j] - 1);
                while (i + h < m && grid[i + h][j] >= h + 1) ++h;
                grid[i][j] = h;
                res += h - 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = m - 1; i >= 0; --i) {
                if (copy[i][j] < 1) continue;
                int h = 1;
                if (i < m - 1) h = max(h, copy[i + 1][j] - 1);
                while (i - h >= 0 && copy[i - h][j] >= h + 1) ++h;
                copy[i][j] = h;
                res += h - 1;
            }
        }
        return res;
    }
};