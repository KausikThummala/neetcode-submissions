class Solution {
public:
    int maxArea(vector<int>& heights) {
        //find the max_area
        //use two pointer approach here
        int max_area=0;
        int area=0;
        int l=0;
        int r=heights.size()-1;
        while(l<=r){
            int height=min(heights[l],heights[r]);
            int width=r-l;
            area=height*width;
            max_area=max(max_area,area);
            if(heights[l]< heights[r]) l++;
            else r--;
        }
        return max_area;
        
    }
};
