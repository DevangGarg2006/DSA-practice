class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        k = k % total;

        vector<vector<int>> newGrid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;            
                int newIdx = (idx + k) % total;  

                int ni = newIdx / m;             
                int nj = newIdx % m;            

                newGrid[ni][nj] = grid[i][j];
            }
        }
        return newGrid;
    }
};