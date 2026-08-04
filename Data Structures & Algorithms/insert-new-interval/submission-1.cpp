class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //now add all the intervals that come before the new interval
        vector<vector<int>> res;
        int i=0;
        int n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        //merge the overlapping interval
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        //push back the merged interval
        res.push_back(newInterval);
        //push_back the non -overlapping intervals that come after the newInterval
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
        
    }
};
