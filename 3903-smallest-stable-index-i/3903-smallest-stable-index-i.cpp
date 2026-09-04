class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        int ma=INT_MIN;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++){
             ma=max(nums[i],ma);
            int mi=INT_MAX;
             for (int j = i; j < n; j++) {
                mi = min(mi, nums[j]);
            }
            if(ma-mi<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};