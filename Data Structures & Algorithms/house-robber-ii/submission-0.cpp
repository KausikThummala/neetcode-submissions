class Solution {
public:
    int helper(vector <int> &arr){
        int rob1=0;
        int rob2=0;
        for(int i=0;i<arr.size();i++){
            int temp=max(rob1+arr[i],rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        //there is an edge case what if the vector only has one element
        if(nums.size()==1){
            return nums[0];
        }
        vector <int> case1(nums.begin(),nums.end()-1);
        vector <int> case2(nums.begin()+1,nums.end());
        return max(helper(case1),helper(case2));
        
    }
};
