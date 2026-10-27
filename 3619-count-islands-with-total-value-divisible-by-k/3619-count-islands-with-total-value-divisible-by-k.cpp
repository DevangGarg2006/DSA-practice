class Solution {
public:
    long long dfs(int i,int j,int m,int n,vector<vector<int>>&grid){

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 ){
            return 0;
        }

      

        long long sum=grid[i][j];
        grid[i][j]=0;

        sum+=dfs(i+1,j,m,n,grid);
        sum+=dfs(i-1,j,m,n,grid);
        sum+=dfs(i,j+1,m,n,grid);
        sum+=dfs(i,j-1,m,n,grid);   
           return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid[0].size();
        int m=grid.size();

      
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 ){
                    long long sum=dfs(i,j,m,n,grid);

                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};