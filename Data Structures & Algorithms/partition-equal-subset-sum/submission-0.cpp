class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum1=0;
        for(int i=0;i<nums.size() ;i++){
            sum1+=nums[i];
        }
        if(sum1%2==1){
            return false;
        }
        int target=sum1/2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i=nums.size()-1;i>=0;i--){
            unordered_set<int> nextdp;
            for(auto t: dp){
                nextdp.insert(t);
                nextdp.insert(t+nums[i]);
            }
            dp=nextdp;


        }
        if(dp.contains(target)){
            return true;
        }
        return false;


        
    }
};
