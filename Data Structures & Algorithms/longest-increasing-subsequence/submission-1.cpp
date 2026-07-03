class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector <int> dp (n,1);
        int max_len=0;
        //now it is a form of a dp so we need to find way to stores the length
        //here lets start from the 1 as dp[0]=1
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            max_len=max(max_len,dp[i]);
        }
        
        return max_len;
        
    }
};
