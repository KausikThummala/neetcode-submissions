class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #so here we are not allowing duplicates
        sett=set(nums)
        #converting the nums into a set automatically removes the duplicates
        longest=0
        for num in list(sett):
            if num-1 not in sett:
                length=1
                next_num=num+1
                while next_num in sett:
                    length+=1
                    next_num+=1
                longest=max(longest,length)
        return longest
        