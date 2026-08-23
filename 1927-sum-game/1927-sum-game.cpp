class Solution {
public:
    bool sumGame(string num) {
        int lQM = 0, rQM = 0;
        int lsum = 0, rsum = 0;

        int n = num.size();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lQM++;
            else
                lsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rQM++;
            else
                rsum += num[i] - '0';
        }

       
        if ((lQM + rQM) % 2)
            return true;

        int diff = lsum - rsum;
        int qmDiff = rQM - lQM;

    
        return 2 * diff != qmDiff * 9;
    }
};