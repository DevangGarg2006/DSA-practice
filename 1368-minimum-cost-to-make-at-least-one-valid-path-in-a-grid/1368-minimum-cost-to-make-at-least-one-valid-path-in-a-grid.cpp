class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});


        while(!dq.empty()){
            auto [x,y] = dq.front();
            dq.pop_front();

             for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int cost = (grid[x][y] == d + 1) ? 0 : 1;
                
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});//cost 0 so same move so this give min path so first this should be procceed
                    else
                        dq.push_back({nx, ny});
                }
        }
        }
        return dist[m-1][n-1];
    }
};