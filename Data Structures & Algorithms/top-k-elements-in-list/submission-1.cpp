class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //how to solve it u can solve it via bucket sort
        //where u use the freqs as the indices
        unordered_map<int,int> mpp;
        for(auto num: nums) mpp[num]++;
        vector<vector<int>> buckets(nums.size()+1);
        for(auto cell: mpp){
            int index=cell.second;
            int val=cell.first;
            buckets[index].push_back(val);
        }
        vector<int> ans;
        for(int i=buckets.size()-1;i>=0;i--){
            for(auto x: buckets[i]){
                ans.push_back(x);
                if(ans.size()==k) return ans;


            }
        }
        return {};
        
    }
};
