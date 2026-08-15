class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool nonz=false;
        for(int i:nums){
            xr^=i;
            if(i!=0){
                nonz=true;
            }
        }

        if(xr!=0){
            return  nums.size();

        }

        if(nonz==true){
            return nums.size()-1;
        }
        return 0;
    }
};