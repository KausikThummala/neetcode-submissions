class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][n]=m-i;//here word 2 is empty
        }
        for(int j=0;j<=n;j++){
            dp[m][j]=n-j;
        }
        //use a bottom up approach
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                    //as we can match the characters here
                    //so move diagonally
                }
                else{
                    //u have 3 options
                    //we add the one as well as we are accounting for the operation of choosing that operation
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]));
                }
            }
        }
        return dp[0][0];
        
    }
};
