class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int g=INT_MIN;
        int s=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(g<nums[i]){
                g=nums[i];
            }
            if(s>nums[i]){
                s=nums[i];
            }
        }
        return gcd(g,s);
    }
};