class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        stack<int> st;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int h=heights[st.top()];
                st.pop();
                int w=(st.empty()) ? i: i-st.top()-1;
                max_area=max(max_area,h*w);
            }
            st.push(i);
            //keep track of the indices here and push the indices and try to keep a monotonic stack of inc indices
        }
        return max_area;
    }
};
