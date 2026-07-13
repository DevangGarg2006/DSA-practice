class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int minDigit=to_string(low).size();
        int maxDigit=to_string(high).size();

        for(int i=1;i<=9;i++){
            int num=i;
            int next=i+1;
            
            while(to_string(num).size()<minDigit && next<=9){
                num=num*10+next;
                next++;
            }
             while (to_string(num).size()<=maxDigit && next <= 9) {
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
                num = num * 10 + next;
                next++;
            }
            if (to_string(num).size() >= minDigit && to_string(num).size() <= maxDigit) {
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};