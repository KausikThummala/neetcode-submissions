class Solution:
    def climbStairs(self, n: int) -> int:
        #u can use this technique called as memoization
        seen={1:1,2:2}
        def fun(n):
            if n in seen:
                return seen[n]
            else:
                seen[n]=fun(n-1)+fun(n-2)
                return seen[n]
        return fun(n)
        