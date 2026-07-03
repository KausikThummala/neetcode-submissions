class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #u have to create two lists
        n=len(nums)
        right=[0]*n
        left=[0]*n
        
        left[0]=1
        for i in range(1,len(nums)):
            left[i]=left[i-1]*nums[i-1]
        right[n-1]=1
        for i in range(n-2,-1,-1):
            right[i]=right[i+1]*nums[i+1]
        for i in range(n):
            nums[i]=left[i]*right[i]
        return nums
        