class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //how to do  3 sum try to put the sorted array into a set 
        //so as to avoid duplicates
        //map the numbers to their indices
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int val=-(nums[i]+nums[j]);
                if(mpp.contains(val) && mpp[val]!=i && mpp[val]!=j){
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(val);
                    sort(res.begin(),res.end());
                    s.insert(res);
                }
            }
        }
        vector<vector<int>> ans;
        for(auto cell:s){
            ans.push_back(cell);
        }
        return ans;

        
    }
};
