class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //here the input array is sorted so u can do the problem using 
        //two pointers
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum>target) r-=1;
            else if(sum<target) l+=1;
            else return {l+1,r+1};

        }
        
    }
};
