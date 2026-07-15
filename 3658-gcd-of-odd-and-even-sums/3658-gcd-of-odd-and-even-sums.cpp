class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=((2*n)*(n+1))/2;
        
        return gcd(sumOdd,sumEven);
    }
};