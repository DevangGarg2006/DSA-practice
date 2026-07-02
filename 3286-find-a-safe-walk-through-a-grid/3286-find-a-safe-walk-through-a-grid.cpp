class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();        // rows
        int n = grid[0].size();     // cols
        using T = tuple<int,int,int>; // (row, col, remaining health)
        queue<T> q;
        vector<vector<int>> best(m, vector<int>(n, -1)); // store max health seen at (i,j)

        // Initialize starting cell
        int startHealth = (grid[0][0] == 1 ? health - 1 : health);
        if (startHealth <= 0) return false;
        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y, remain] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newRemain = remain - grid[nx][ny];
                    if (newRemain > 0 && newRemain > best[nx][ny]) {
                        best[nx][ny] = newRemain;
                        q.push({nx, ny, newRemain});
                    }
                }
            }
        }
        return false;
    }
};
