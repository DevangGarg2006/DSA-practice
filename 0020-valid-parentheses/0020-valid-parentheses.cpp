class Solution {
public:
    bool isValid(string s) {
        stack<char> stemp;
        for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                stemp.push(ch);
            }
            else{
                if(stemp.empty()){
                    return false;
                }
                int top=stemp.top();
                stemp.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }

            }
        }
         return stemp.empty();

    }
};