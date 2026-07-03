class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //make two vectors left and right
        int n=nums.size();
        vector <int> left(n);
        vector <int> right(n);
        int prefix=1;
        for(int i=0;i<n;i++){
            left[i]=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            right[i]=suffix;
            suffix*=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=left[i]*right[i];
        }
        return nums;

    }
};
