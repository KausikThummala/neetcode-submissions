class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int ,int>> q;
        for(int  i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //push all treasure cells to the queue
                //so as to perform multisource BFS
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto cell =q.front();
                q.pop();
                int r=cell.first;
                int c=cell.second;
                //to traverse in all 4 directions so as to get the inf cells
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr<0 || nr>=m || nc>=n || nc<0 ){
                        continue;
                        //skip if its out of bounds       
                    }
                    if(grid[nr][nc]!=2147483647){
                        continue;
                        //if it is 0 or 1 then skip it
                    }
                    grid[nr][nc]=1+grid[r][c];
                    //adding 1 to the inf cell
                    q.push({nr,nc});
                }
            }
        }
        
        
    }
};
