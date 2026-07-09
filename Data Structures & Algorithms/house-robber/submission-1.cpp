class Solution {
public:
    int rob(vector<int>& nums) {
        //keep two variables where i need to keep track of two choices
        //either rob the house or not rob it
        int rob1=0;
        int rob2=0;
        for(int i=0;i<nums.size();i++){
            int temp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
        
    }
};
