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
    int minMeetingRooms(vector<Interval>& intervals) {
        //now here sort the intervals based on their start times
        //and also use min_heap to get the end_times 
        //see we can reuse that meeting room
        //we can reuse only if current start >= earliastEnding meeting
        //the minheap.size determines the no. of meeting rooms required to schedule all meetings without  
        //any conflicts
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
                return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto interval: intervals){
            int st=interval.start;
            int end=interval.end;
            if(!pq.empty() && pq.top()<= st){
                //i can reuse that room
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
        
    }
};
