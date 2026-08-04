class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //i need to return the minimum number of intervals that i can remove so that the intervals can become
        //non overlapping
        //min removals=total-max intervals i can keep
        int removed=0;
        //sort the intervals based on their end times and in case of overlapping
        //keep the interval with the shorter end time
        sort(intervals.begin(),intervals.end(),
        [](const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];//sort the intervals based on their end times in ascending order
        });
        int prevEnd =intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int curr_st=intervals[i][0];
            if(prevEnd>curr_st){
                removed++;
            }
            else{
                //if its non overlapping then update the prevEnd 
                prevEnd=intervals[i][1];
            }
        }
        return removed;
        
        
    }
};
