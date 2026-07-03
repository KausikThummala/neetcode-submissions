class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res=[0]*len(nums)
        l,r=0,len(nums)-1
        i=len(res)-1
        while i>=0 and l<=r:
            if(abs(nums[l])>abs(nums[r])):
                res[i]=nums[l]*nums[l]
                l+=1
            else:
                res[i]=nums[r]*nums[r]
                r-=1
            i-=1
        return res

        