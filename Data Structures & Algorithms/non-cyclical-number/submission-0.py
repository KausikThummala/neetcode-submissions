class Solution:
    def isHappy(self, n: int) -> bool:
        #u can choose fast and slow pointer approach
        def sumofSquares(n):
            sum1=0
            while n>0:
                rem=n%10
                sum1+=rem*rem
                n=n//10
            return sum1
        fast=slow=n
        while True:
            fast=sumofSquares(sumofSquares(fast))
            slow=sumofSquares(slow)
            if slow==fast:
                break
        return (slow==1)