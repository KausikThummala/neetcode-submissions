class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int max_len=0;
        for(auto num: nums){
            if (!s.contains(num-1)){
                int next_num=num+1;
                int len=1;
                while(s.contains(next_num)){
                    next_num+=1;
                    len+=1;
                }
                max_len=max(max_len,len);
            }
        }
        return max_len;
        
    }
};
