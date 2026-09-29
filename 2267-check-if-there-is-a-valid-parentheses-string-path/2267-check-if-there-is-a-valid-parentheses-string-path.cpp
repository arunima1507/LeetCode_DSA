class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n) % 2 == 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int change = (grid[i][j] == '(') ? 1 : -1;
                int remaining = (m - 1 - i) + (n - 1 - j);

                for (int b = 0; b < m + n; b++) {
                    int prev = b - change;

                    if (prev < 0 || prev >= m + n) continue;

                    bool possible = false;

                    if (i > 0 && dp[i - 1][j][prev])
                        possible = true;

                    if (j > 0 && dp[i][j - 1][prev])
                        possible = true;

                    if (possible && b <= remaining)
                        dp[i][j][b] = true;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};