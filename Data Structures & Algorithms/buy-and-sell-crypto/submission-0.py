class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #we need to find the max_profit
        max_profit=0
        buy_price=prices[0]
        for i in range(1,len(prices)):
            if prices[i]<buy_price:
                buy_price=prices[i]
            else:
                profit=prices[i]-buy_price
                max_profit=max(profit,max_profit)
        return max_profit
        