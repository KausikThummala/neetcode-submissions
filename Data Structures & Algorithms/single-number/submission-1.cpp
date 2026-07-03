class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        //xor is reserved keyword
        for(int i=0;i<nums.size();i++ ){
            res=res^nums[i];
        }
        return res;
        
    }
};
