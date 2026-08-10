class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeat=a;
        int cnt=1;

        while(repeat.size()<b.size()){
            cnt++;
            repeat+=a;
        }

        if(repeat.find(b)!=string::npos) return cnt;

        repeat+=a;
        cnt++;

        if(repeat.find(b)!=string::npos) return cnt;

        return -1;

    }
};