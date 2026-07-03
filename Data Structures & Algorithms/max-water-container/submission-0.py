class Solution:
    def maxArea(self, heights: List[int]) -> int:
        #take two variables
        area=0
        max_area=0
        l,r=0,len(heights)-1
        while l<r:
            width=r-l
            height=min(heights[l],heights[r])
            area=height*width
            max_area=max(area ,max_area)
            if (heights[l]<heights[r]):
                l+=1
            #here we are changing the min height as thats what decides our height
            else:
                r-=1
        return max_area
            
        