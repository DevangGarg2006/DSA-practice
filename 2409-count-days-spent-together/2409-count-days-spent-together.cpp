class Solution {
public:
    int convert(string s){
        vector<int> days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int mon=stoi(s.substr(0,2));
        int day=stoi(s.substr(3,2));

        for(int i=0;i<mon-1;i++){
            day+=days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aArrDay=convert(arriveAlice);
        int aLeaveDay=convert(leaveAlice);
        int bArrDay=convert(arriveBob);
        int bLeaveDay=convert(leaveBob);

        int start=max(aArrDay,bArrDay);
        int end=min(aLeaveDay,bLeaveDay);

        return max(0,end-start+1);

    }
};