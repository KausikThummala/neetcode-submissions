class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //keep track of the index by maintaining a hashmap so as to map elements
        unordered_map <int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int complement=target - nums[i];
            if(mpp.count(complement)){
                return {mpp[complement],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
        
    }
};
