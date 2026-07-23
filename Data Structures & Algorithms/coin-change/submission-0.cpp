class Solution {
public:
//here dp[a] represents the min no. of coins that are used to represent the amount
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int a=1;a<=amount;a++){
            for(int coin: coins){
                if(a-coin>=0){
                    //get the min for each and every coin
                    dp[a]=min(dp[a],1+dp[a-coin]);
                    //here the one represents that u are using this coin
                }
            }
        }
        return (dp[amount]>amount) ? -1: dp[amount];
    }
};
