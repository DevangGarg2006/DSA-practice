class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=1;
        int len=0;

        int n=haystack.size();
        int m=needle.size();

        vector<int>LPS(m,0);
        while(i<m){
            if(needle[i]==needle[len]){
                LPS[i++]=++len;
            }
            else{
                if(len!=0){
                    len=LPS[len-1];
                }
                else{
                    LPS[i++]=0;
                }
            }
        }

        i=0;
        int j=0;
        
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            
               if (j == m) return i - j;
            
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) j = LPS[j - 1];
                else i++;
            }
        }
        return -1;
    }
};