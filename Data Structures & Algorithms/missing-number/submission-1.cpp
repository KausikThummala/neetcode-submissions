class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //we have to find the xor from 1 to n
        int res=0;
        for(int i=1;i<=nums.size();i++){
            res^=i;
        }
        int res_arr=0;
        for(int i=0;i<nums.size();i++){
            res_arr^=nums[i];
        }
        return (res_arr^res);
        
    }
};
