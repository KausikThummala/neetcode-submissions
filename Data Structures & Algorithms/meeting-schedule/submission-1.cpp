/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //even if there is one overlap then immediately return false
        //sort them based on their start times
        //its not a vector, its a class called Interval
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b ){
            return a.start<b.start;
        });
        for(int i=1;i<intervals.size();i++){
            int prevEnd=intervals[i-1].end;
            int curr_st=intervals[i].start;
            if(prevEnd>curr_st){
                return false;
            }
        }
        return true;
        
    }
};
