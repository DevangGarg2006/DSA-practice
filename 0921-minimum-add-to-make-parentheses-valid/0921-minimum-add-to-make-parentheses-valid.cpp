class Solution {
public:
    int minAddToMakeValid(string s) {
        int insert=0;

        int bal=0;
        

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                bal++;
            }
            else{
                bal--;
                if(bal<0){
                    insert++;
                    bal++;
                }
            }
        }

        return bal+insert;
    }
};