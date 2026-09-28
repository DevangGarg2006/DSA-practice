class Solution {
public:
    int maxDepth(string s) {
        stack<char> str;
        int maxl=0;
        int len=0;
        for(auto &ch:s){
            if(ch=='('){
                str.push(ch);
                len++;
                maxl=max(maxl,len);
            }
            else if(ch==')'){
                str.pop();
                len--;
            }
        }
        return maxl;
    }
};