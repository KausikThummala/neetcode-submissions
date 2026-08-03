class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int res=0;
        while(r<nums.size()-1){
            int farth=0;
            //use BFS on this 1d dp and solve it by keeping track of how far can  jump
            for(int i=l;i<=r;i++){
                farth=max(farth,i+nums[i]);
            }
            l=r+1;
            //l corresponds to the start of the window and r keeps track of the end which the farthest i can
            //jump
            r=farth;
            res+=1;
        }
        return res;
        
    }
};
