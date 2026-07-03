class Solution {
public:
    int search(vector<int>& nums, int target) {
      //for binary serach to work,the array needs to be sorted
      int l=0;
      int r=nums.size()-1;
      while(l<=r){
        int mid=l+((r-l)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target){
            r=mid-1;
        }
        else l=mid+1;
      }
      return -1;
        
    }
};
