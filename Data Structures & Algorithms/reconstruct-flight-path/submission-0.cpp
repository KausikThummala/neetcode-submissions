class Solution {
public:
    //use a helper function so as to add nodes to the ans vector
    //add only those nodes which hav no outgoing edges
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
    vector <string> ans;
    void dfs(string res){
        while(!graph[res].empty()){
            string next=graph[res].top();
            graph[res].pop();
            dfs(next);
        }
        ans.push_back(res);
        //only add the edges with no outgoing edges;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t: tickets){
            graph[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        //return the correct itenary
        
        
    }
};
