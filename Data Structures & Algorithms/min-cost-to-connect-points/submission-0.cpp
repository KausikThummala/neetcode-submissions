class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int edges_used=0;
        int n=points.size();
        vector<bool> visited(n,false);
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        //the cost and the index
        int total=0;
        while(edges_used<n){
            auto [cost,curr]=pq.top();
            pq.pop();
            if(visited[curr]) continue;
            //this means that the node is already in the MST
            visited[curr]=true;
            edges_used+=1;
            total+=cost;
            for(int next=0;next<n;next++){
                if(!visited[next]){
                    int dist=abs(points[curr][0]-points[next][0])+abs(points[next][1]-points[curr][1]);
                    pq.push({dist,next});
                }
            }
        }
        return total;
        
    }
};
