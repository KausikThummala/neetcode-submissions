class Solution:
    def hammingWeight(self, n: int) -> int:
        #here we need to find the hamming weight
        c=0
        while n>0:
            n=n&(n-1)
            c+=1
        return c
        