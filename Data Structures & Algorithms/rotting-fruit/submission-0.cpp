class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        //keep track of all the fresh oranges and push the indices of
        //the rotten oranges into a queue
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fresh+=1;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int minutes=0;
        int dc[]={0,0,-1,1};
        //so as to traverse the neighboring fresh oranges connected to the rotten oranges
        while(!q.empty() && fresh>0){
            int size=q.size();
            while(size--){
                auto cell=q.front();
                q.pop();
                int r=cell.first;
                int c=cell.second;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        //this is done so as to convert the fresh oranges next
                        //to rotten oranges
                        //we dont process this oranges immediately
                        //instead we wait for the next minute
                        grid[nr][nc]=2;
                        fresh-=1;
                        q.push({nr,nc});
                    }

                }
            }
            minutes++;

        }
        return ((fresh==0) ? minutes:-1 );

        
    }
};
