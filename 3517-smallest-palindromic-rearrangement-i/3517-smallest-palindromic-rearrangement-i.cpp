class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }

        string half="";
        string middle="";
        for(char ch='a';ch<='z';ch++){
            int count=freq[ch-'a'];
            half.append(count/2,ch);
            if(count%2==1){
                middle=string(1,ch);
            }

        }
        string result=half+middle;

        reverse(half.begin(),half.end());
        result+=half;
        return result;  
    }
};