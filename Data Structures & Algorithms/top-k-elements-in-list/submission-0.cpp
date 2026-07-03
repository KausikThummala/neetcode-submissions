class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //here use the concept of bucket sort where frequncies are the indices 
        //and go from the back
        unordered_map <int,int> mpp;
        for(int num: nums){
            mpp[num]++;
        } 
        //now we have to create a bucket
        vector <vector <int>> bucket(nums.size()+1);
        //a vector of vectors
        //say we have 1,1,1,1,1,1 then freq 6 should be in the indices
        for(auto & it : mpp){
            int num=it.first;
            int freq=it.second;
            bucket[freq].push_back(num);
        }
        //now we have to create a vector ans
        vector <int> ans;
        //and go from the back
        for(int i=bucket.size()-1;i>=0;i--){
            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;


        
    }
};
