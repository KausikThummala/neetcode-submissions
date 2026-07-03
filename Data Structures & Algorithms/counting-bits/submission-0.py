class Solution:
    def countBits(self, n: int) -> List[int]:
        #make a function which counts the number of one bits
        def count(n):
            c=0
            while n>0:
                n=n&(n-1)
                #this operation removes the right most set bit
                #and we count the number of set bits that we have removed
                c+=1
            return c
        res=[]
        for i in range(n+1):
            res.append(count(i))
        return res



        