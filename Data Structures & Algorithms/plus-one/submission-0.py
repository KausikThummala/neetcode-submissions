class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        #brute force way is to convert it into a string
        #but no i will do it in another way
        #instead we will get two cases
        #case 1 no carry
        carry=1
        for i in range(len(digits)-1,-1,-1):
            sum1=digits[i]+carry
            carry=sum1//10
            sum1=sum1%10
            digits[i]=sum1
        if carry==0:
            return digits
        #if thats not the case then we intilialize with another list
        res=[0]*(len(digits)+1)
        res[0]=carry
        for i in range(1,len(digits)+1):
            res[i]=digits[i-1]
        return res



        