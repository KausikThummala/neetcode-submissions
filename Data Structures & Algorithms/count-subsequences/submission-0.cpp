class Solution {
public:
    int dfs(string &s,string &t,int i,int j,vector<vector<int>>  &dp){
        if(j==t.size()) return 1;//we have successfully formed t
        if(i==s.size()) return 0;//we have run out of chars
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            //use it or skip it
            return dp[i][j]=dfs(s,t,i+1,j+1,dp) + dfs(s,t,i+1,j,dp);
        }
        //here u are having only one choice skipping it
        else return dp[i][j]=dfs(s,t,i+1,j,dp);

    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return dfs(s,t,0,0,dp);
        
    }
};
