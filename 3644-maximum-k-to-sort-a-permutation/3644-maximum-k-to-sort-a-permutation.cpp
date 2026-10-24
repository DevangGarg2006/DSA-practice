class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=-1;
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                if(ans==-1){
                    ans=nums[i];
                }
                else
                ans&=nums[i];
            }
        }
        return ans;
    }
};