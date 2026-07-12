class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin=1;
        int currMax=1;
        int res=*max_element(nums.begin(),nums.end());
        for(int n: nums){
            if(n==0){
                //reset both max and min to 1 and then continue
                currMax=1;
                currMin=1;
                continue;
            }
            int tmp=n*currMax;
            currMax=max(n,n*currMax);//here we are taking n as take the case of -1,8 then min=1,max=1 so we have take n as well
            currMax=max(currMax,n*currMin);
            currMin=min(n*currMin,tmp);
            currMin=min(currMin,n);
            res=max(res,currMax);
        }
        return res;
        
    }
};
