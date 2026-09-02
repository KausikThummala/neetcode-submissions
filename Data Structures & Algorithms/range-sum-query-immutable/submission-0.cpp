class NumArray {
public:
    vector<int> nums1;
    NumArray(vector<int>& nums) {
        //get the prefix array here
        int n=nums.size();
        nums1.resize(n);
        nums1[0]=nums[0];
        for(int i=1;i<n;i++){
            nums1[i]=nums1[i-1]+nums[i];
        }
        //got the prefix sum array here so



        
    }
    
    int sumRange(int left, int right) {
        if(left==0) return nums1[right];
        else return nums1[right]-nums1[left-1];


    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */