class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        vector<vector<int>> best(n, vector<int>(n, -1));
        priority_queue<tuple<int,int,int>> pq; // (safety, x, y)
        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [safety, x, y] = pq.top(); pq.pop();
            if (x == n-1 && y == n-1) return safety; // reached end

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<n && ny<n) {
                    int nsafety = min(safety, dist[nx][ny]);
                    if (nsafety > best[nx][ny]) {
                        best[nx][ny] = nsafety;
                        pq.push({nsafety, nx, ny});
                    }
                }
            }
        }
        return -1; 
    }
};