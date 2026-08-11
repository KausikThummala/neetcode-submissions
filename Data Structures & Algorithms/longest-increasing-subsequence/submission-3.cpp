class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //find the longest increasing subsequence
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    //can i extend the LIS ending at index i towards the left
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int max1=*max_element(dp.begin(),dp.end());
        return max1;
        
    }
};
