class Solution {
public:
    bool dfs(vector<vector<int>> & adj,vector <bool> & visit,vector<bool> &path ,int crs){
        if(path[crs]) return false;
        //this course is already visited in my path so return false
        if(visit[crs]) return true;
        //a cycle has not been detected and i dont see this crs in my current dfs path
        //so this crs has been processesed earlier
        visit[crs]=true;
        path[crs]=true;
        for(auto next_course: adj[crs]){
            if(!dfs(adj,visit,path,next_course)) return false;
        }
        path[crs]=false;
        //remove this course from the current dfs path
        return true;


    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visit(numCourses,false);
        vector<bool> path(numCourses,false);
        //path over here used to check if our course is currently part of the DFS path
        //visit checks if we have already visited it before
        vector<vector<int>> adj(numCourses);
        for (auto pre: prerequisites){
            int prereq=pre[1];
            int crs=pre[0];
            adj[prereq].push_back(crs);
        }
        for(int course=0;course<numCourses;course++){
            if(!dfs(adj,visit,path,course)) return false;
        }
        return true;

    }
};
