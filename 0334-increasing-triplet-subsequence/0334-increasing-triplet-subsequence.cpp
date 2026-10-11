class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int sec=INT_MAX;

        for(int x:nums){
            if(x<=first){
                first=x;
            }
            else if(x<=sec){
                sec=x;
            }
            else{
                return true;
            }
        }

        return false;
    }
};