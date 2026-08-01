class Solution {
public:
    bool helper(int i,int j,vector<int>&nums,int p1,int p2,bool turn){
        if(i>j){
            return p1>=p2;
        }

        if(turn){
            bool pickleft=helper(i+1,j,nums,p1+nums[i],p2,false);
            bool pickright=helper(i,j-1,nums,p1+nums[j],p2,false);
            return pickleft||pickright;
        }
        else{
            bool pickleft=helper(i+1,j,nums,p1,p2+nums[i],true);
            bool pickright=helper(i,j-1,nums,p1,p2+nums[j],true);
            return pickleft&&pickright;
            
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return helper(0,nums.size()-1,nums,0,0,true);
    }
};