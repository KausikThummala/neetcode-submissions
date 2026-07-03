class Solution {
public:
    int trap(vector<int>& height) {
        //keep track of the leftmax and the right max and then add up the water trapped in the
        //rocks
        int leftMax=0;
        int rightMax=0;
        int waters=0;
        int l=0;
        int r=height.size()-1;
        while(l<=r){
            if(height[l]<height[r]){
                leftMax =max(height[l],leftMax);
                waters +=leftMax-height[l];
                l++;
            }
            else{
                rightMax=max(height[r],rightMax);
                waters +=rightMax -height[r];
                r--;
            }

        }
        return waters;
        
        
    }
};
