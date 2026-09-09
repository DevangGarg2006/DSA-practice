class Solution {
public:
    long long countCommas(long long n) {
        int digi=0;
        
        long long temp = n;

        while(temp>0){
            digi++;
            temp/=10;
        }
        long long boundary=1;
        long long ans=0;
        while(digi>0){
            if(digi-3>0){
                boundary*=1000;
            
            ans+=(n-boundary+1);
            }
            digi-=3;
        }
        return ans;
    }
};