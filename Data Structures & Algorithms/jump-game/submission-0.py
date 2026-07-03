class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farth=0
        for i,num in enumerate(nums):
            if i>farth:
                return False
            farth=max(num+i,farth)
        return True
        