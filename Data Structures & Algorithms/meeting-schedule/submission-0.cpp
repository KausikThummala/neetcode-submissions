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
        sort(intervals.begin(),intervals.end(),
        [](const Interval &a,const Interval &b){
            return a.start<b.start;
        });
        //here sort cannot compare two interval objects so we just need to
        //pass in a custom comparator to tell sort to sort interval objects based on
        //the start values in the ascending order 
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<intervals[i-1].end){
                return false;
            }
        }
        return true;
        
    }
};
