class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        const int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());

        vector<int>power(n,1);

        for(int i=1;i<n;i++){
            power[i]=(power[i - 1] * 2) % MOD;
        }
        
        int left=0;
        int right=n-1;

        int cnt=0;

        while(left<=right){
            if(nums[left]+nums[right]<=target){
                  cnt = (cnt + power[right - left]) % MOD;
                left++;
            }
            else{
                right--;
            }
        }
        return cnt;
    }
};