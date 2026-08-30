class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //keep track of the min price and get the max_profit here
        int buy_price=prices[0];
        int max_profit=0;
        for(auto price: prices){
            buy_price=min(buy_price,price);
            int profit=price-buy_price;
            max_profit=max(max_profit,profit);
        }
        return max_profit;
        
    }
};
