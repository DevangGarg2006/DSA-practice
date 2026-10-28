class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>&grid,int m,int n){
        if(i>=m || j>=n ||i<0 ||j<0){
            return false;
        }

        if(grid[i][j]==1){
            return true;
        }
        grid[i][j] = 1;
        bool up=solve(i-1,j,grid,m,n);
        bool down=solve(i+1,j,grid,m,n);
        bool left=solve(i,j-1,grid,m,n);
        bool right=solve(i,j+1,grid,m,n);

        return up&& down && left&& right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0){
                    if(solve(i,j,grid,m,n)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};