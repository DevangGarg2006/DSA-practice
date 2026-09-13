class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpr=nums[0];
        int minpr=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int temp=maxpr;
            maxpr=max({nums[i],maxpr*nums[i],minpr*nums[i]});
            minpr=min({nums[i],temp*nums[i],minpr*nums[i]});
            ans=max(maxpr,ans);
        }
        return ans;
    }
};