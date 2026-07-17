class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas=0;
        int sumcost=0;
        for(int i=0;i<gas.size();i++){
            sumgas+=gas[i];
            sumcost+=cost[i];
        }
        if(sumgas<sumcost) return -1;
        //otw a soln exists
        int total=0;
        int resIdx=0;
        for(int i=0;i<gas.size();i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                total=0;
                resIdx=i+1;
            }
        }
        return resIdx;


        
    }
};
