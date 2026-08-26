class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
      
        int l=0;
        int n=s.size();
        int cnt=0;

        int minL=INT_MAX;
        string ans="";
        
        for(int r=0;r<n;r++){
            if(s[r]=='1'){
                cnt++;
                
            }
            while(cnt>=k){
                    int len=r-l+1;
                    string sub=s.substr(l,r-l+1);

                    if(len<minL || (len==minL && ans>sub)){
                        minL=len;
                        ans=sub;
                    }
                    
                    if(s[l]=='1') cnt--;

                    l++;

                }
        }
        return ans;
    }
};