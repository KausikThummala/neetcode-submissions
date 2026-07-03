class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        #here we have to define a rotate function from 0 to k-1 and k to len(nums)
        def reverse(nums:List[int],a:int,b:int):
            l,r=a,b
            while l<=r:
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
                r-=1
        if(k>len(nums)):
            k=k%len(nums)
        reverse(nums,0,len(nums)-1)
        reverse(nums,0,k-1)
        reverse(nums,k,len(nums)-1)
        
        


        