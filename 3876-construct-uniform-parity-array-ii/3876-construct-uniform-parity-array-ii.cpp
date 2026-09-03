class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allodd = false;

        int mino=INT_MAX;
        int oi=-1;
        int mine=INT_MAX;
        int ei=-1;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0){
                mino = min(mino, nums1[i]);
                oi=i;
            }
            else{
                mine=min(mine,nums1[i]);
                ei=i;
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0) {
                 if ((nums1[i] - mino) >= 1 &&
                           (nums1[i] - mino) % 2 != 0 && oi!=i) {
                    allodd = true;
                } else {
                    allodd = false;
                    break;
                }
            }
            else{
                allodd=true;
            }
        }

        bool alleven=false;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
               if ((nums1[i] - mino) >= 1 &&
                           (nums1[i] - mino) % 2 == 0 && ei!=i) {
                    alleven = true;
                           }
                else{
                    alleven=false; 
                    break;       
                }
            
        }
            else{
                alleven=true;
            }
        }
        return alleven||allodd;
    }
};