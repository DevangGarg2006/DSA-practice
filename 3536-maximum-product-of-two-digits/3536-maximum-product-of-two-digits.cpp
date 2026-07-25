class Solution {
public:
    int maxProduct(int n) {
        int firt=-1;
        int snd=-1;

        while(n>0){
            int digi=n%10;

            if(digi>firt){
                snd=firt;
                firt=digi;
            }
            else if(digi>snd){
                snd=digi;
            }
            n/=10;
        }

        return snd!=-1?firt*snd:0;
    }
};