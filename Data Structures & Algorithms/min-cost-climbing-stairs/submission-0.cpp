class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one=cost[0];
        int two=cost[1];
        for(int i=2;i<cost.size();i++){
            int tmp=cost[i]+min(one,two);
            one=two;
            two=tmp;
        }
        return min(two,one);
        
    }
};
