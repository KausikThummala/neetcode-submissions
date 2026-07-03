class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        #in python it is very easy to to do this prob
        #write down the base case
        n=len(nums)
        res=[]
        sol=[]
        def backtrack(i):
            if(i==n):
                res.append(sol[:])
                return
            #now we have two choices either to include or exclude
            backtrack(i+1)

            sol.append(nums[i])
            backtrack(i+1)
            sol.pop()
        backtrack(0)
        return res
        