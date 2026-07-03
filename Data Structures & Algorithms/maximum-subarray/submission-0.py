class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #u can use kadanes algo
        ms=float('-inf')
        cs=0
        for num in nums:
            cs+=num
            ms=max(ms,cs)
            if cs<0:
                cs=0
            #here the negatives are decreasing the cs
        return ms
        