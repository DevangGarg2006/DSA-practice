class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int ans=1;
        int inc=1;
        int des=1;


        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                des=1;
            }
            else if(nums[i]<nums[i-1]){
                des++;
                inc=1;
            }
            else{
                des=1;
                inc=1;
            }
            ans=max(ans,max(des,inc));
        }
        return ans;
    }
};