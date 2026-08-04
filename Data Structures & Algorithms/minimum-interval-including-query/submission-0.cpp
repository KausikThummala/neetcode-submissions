class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //use a minheap which gives u smallest interval that contains the query
        vector<int> res(queries.size(),-1);
        //sort the intervals based on the start times
        //process the queries in the increasing order
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> sorted_Queries;
        for(int i=0;i<queries.size();i++){
            sorted_Queries.push_back({queries[i],i});
        }
        sort(sorted_Queries.begin(),sorted_Queries.end());
        int i=0;
        //the first element is the size and second element is the end time
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //here u would only get the smallest valid interval that is containing the query
        int n=intervals.size();
        for(auto [query,idx]:sorted_Queries){
            while(i<n && intervals[i][0]<=query){
                //add all the valid intervals into the minheap
                int start=intervals[i][0];
                int end=intervals[i][1];
                int size=end-start+1;
                pq.push({size,end});
                i++;
            }
            //now remove all the invalid intervals
            while(  !pq.empty() && pq.top().second<query ){
                pq.pop();
                //check if the interval we have pushed is valid 
                //if the query > end then its not valid
            }
            if(!pq.empty()){
                res[idx]=pq.top().first;
                //we have got the smallest interval which is valid
            }
        }
        return res;
        
    }
};
