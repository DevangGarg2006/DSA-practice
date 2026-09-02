class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool even=false;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                for(int j=i+1;j<nums1.size();j++){
                    if(abs(nums1[i]-nums1[j])%2==0){
                        even=true;
                    }
                    else{
                        even=false;
                    }
                }
            }
            else{
                even=true;
            }
        }

        bool odd=false;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                for(int j=i+1;j<nums1.size();j++){
                    if(abs(nums1[i]-nums1[j])%2!=0){
                        odd=true;
                    }
                    else{
                        odd=false;
                    }
                }
            }
            else{
                odd=true;
            }
        }
        return (odd||even);
    }
};