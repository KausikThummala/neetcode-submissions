class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //here u have to use djikstra's algorithm
        //so keep a min heap where u store the time,row and col
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;
        while(!pq.empty()){
            auto cell=pq.top();
            pq.pop();
            int currtime=cell[0];
            int r=cell[1];
            int c=cell[2];
            if(r==n-1 && c==n-1){
                return currtime;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                //this is done so that i dont process it again
                if(nr<0 || nc<0 || nr>=n || nc>=n || visited[nr][nc]){
                    continue;
                }
                //if it is out of bounds then
                //set visited to true 
                visited[nr][nc]=true;
                pq.push({max(grid[nr][nc],currtime),nr,nc});


            }
        }
        return 0;



        
    }
};
