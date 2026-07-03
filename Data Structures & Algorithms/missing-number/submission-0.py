class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #there are no duplicates so use the xor operator
        xor=0
        for num in nums:
            xor^=num
        
        for i in range(len(nums)+1):
            xor^=i
        return xor

        