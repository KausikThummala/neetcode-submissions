class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret=set()
        d={}
        for i,num in enumerate(nums):
            d[num]=i
        #here we are iterating over all the elements of the list
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                z=-(nums[i]+nums[j])
                if z in d and d[z]!=i and d[z]!=j:
                    triple=sorted([nums[i],nums[j],z])
                    ret.add(tuple(triple))
        res=[]
        for t in list(ret):
            res.append(t)
        return res

        