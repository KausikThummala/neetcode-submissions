class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int curr_start=intervals[i][0];
            int lastEnd=res.back()[1];
            if(lastEnd>= curr_start){
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            else{
                //push the non -overlapping intervals into the 2d vector
                res.push_back(intervals[i]);
            }
        }
        return res;
        
    }
};
