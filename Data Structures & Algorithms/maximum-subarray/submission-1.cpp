#include <limits.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //use kadanes algorithm
        int MS=INT_MIN;
        int CS=0;
        for(int i=0;i<nums.size();i++){
            CS+=nums[i];
            MS=max(MS,CS);
            if(CS<0) CS=0;
        }
        return MS;

    }
};
