class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //in case of subarray sum equals k try to keep a prefix sum hashmap
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int curr=0;
        int count=0;
        for(auto num: nums){
            curr+=num;
            if(mpp.count(curr-k)){
                count+=mpp[curr-k];
            }
            mpp[curr]++;
        }
        return count;
        
    }
};