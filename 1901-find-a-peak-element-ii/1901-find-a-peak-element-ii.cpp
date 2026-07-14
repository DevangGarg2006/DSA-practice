class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int cols=mat[0].size();

        int left=0;
        int right=cols-1;

        while(left<=right){
            int midcol=left+(right-left)/2;

            int maxrow=0;
            for(int i=1;i<row;i++){
                if(mat[i][midcol]>mat[maxrow][midcol]){
                    maxrow=i;
                }
            }
            int leftVal=(midcol-1>=0)?mat[maxrow][midcol-1]:-1;
            int rightVal=(midcol+1<cols)?mat[maxrow][midcol+1]:-1;

            if(mat[maxrow][midcol]>leftVal && mat[maxrow][midcol]>rightVal){
                return {maxrow,midcol};
            }
            else if(mat[maxrow][midcol]<leftVal){
                right=midcol-1;
            }
            else{
                left=midcol+1;
            }
        }
        return {-1,-1};
    }
};