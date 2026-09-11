class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx=0;
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);

            if(mx==i){
                c++;
            }
        }
        return c;
    }
};