class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //to find the max profit
        int buy=prices[0];
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            max_profit=max(max_profit,prices[i]-buy);

        }
        return max_profit;
    }
};
