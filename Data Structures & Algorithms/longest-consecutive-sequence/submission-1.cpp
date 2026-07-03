class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> st(nums.begin(),nums.end());
        int max_len=0;
        for(int num:nums){
            if(!(st.count(num-1))){
                int curr_num=num;
                int len=1;
                while(st.count(curr_num+1)){
                    curr_num+=1;
                    len+=1;
                }
                max_len=max(len,max_len);
            }
        }
        return max_len;
        
    }
};
