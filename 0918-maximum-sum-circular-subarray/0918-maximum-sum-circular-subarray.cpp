class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=nums[0];
        int ansmx=nums[0];
        int mn=nums[0];
        int sum=nums[0];
        int ansmn=nums[0];

        int n=nums.size();

        for(int i=1;i<n;i++){
            mx=max(mx+nums[i],nums[i]);
            mn=min(mn+nums[i],nums[i]);
            ansmx=max(mx,ansmx);
            ansmn=min(mn,ansmn);
            sum+=nums[i];
        }
        if (ansmx < 0)
            return ansmx;


        return max(ansmx,sum-ansmn);
    }
};