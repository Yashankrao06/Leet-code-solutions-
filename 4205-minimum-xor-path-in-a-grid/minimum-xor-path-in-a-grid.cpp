class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<unordered_set<int>> dp(n);
        dp[0].insert(grid[0][0]);
        for (int j = 1; j < n; ++j) {
            for (int val : dp[j - 1]) dp[j].insert(val ^ grid[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            unordered_set<int> col0;
            for (int val : dp[0]) col0.insert(val ^ grid[i][0]);
            dp[0] = move(col0);
            
            for (int j = 1; j < n; ++j) {
                unordered_set<int> cell;
                for (int val : dp[j]) cell.insert(val ^ grid[i][j]);
                for (int val : dp[j - 1]) cell.insert(val ^ grid[i][j]);
                dp[j] = move(cell);
            }
        }
        int ans = 1e9;
        for (int val : dp[n - 1]) ans = min(ans, val);
        return ans;
    }
};
