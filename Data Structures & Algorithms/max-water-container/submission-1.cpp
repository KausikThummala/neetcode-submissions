class Solution {
public:
    int maxArea(vector<int>& heights) {
        //to find the max_area of the container
        int l=0;
        int r=heights.size()-1;
        int max_area=0;
        int height=0;
        while(l<r){
            height=min(heights[l],heights[r]);
            max_area=max((r-l)*height,max_area);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
            
            
        }
        return max_area;

        
    }
};
