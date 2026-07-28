class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n), nse(n);

        // Previous Smaller Element
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Smaller Element
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};
