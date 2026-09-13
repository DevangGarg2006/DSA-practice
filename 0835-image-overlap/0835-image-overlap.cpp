class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        
        for(int diry=-(n-1);diry<=n-1;diry++){
            for(int dirx=-(n-1);dirx<=n-1;dirx++){
                int cnt=0;

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int nx=i+dirx;
                        int ny=j+diry;

                        if(nx>=0 && nx<n && ny>=0 && ny<n && img1[i][j]==1 && img2[nx][ny]==1){
                            cnt++;
                        }
                    }
                }
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};