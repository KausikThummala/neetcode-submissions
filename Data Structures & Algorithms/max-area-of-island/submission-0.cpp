class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        //if our indexes are out of bounds return 0;
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        //it means its water or visited
        if(grid[i][j]==0){
            return 0;
        }
        //now set it to zero
        grid[i][j]=0;
        int area=1;
        area+=dfs(grid,i+1,j);
        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i,j+1);
        area+=dfs(grid,i,j-1);
        //use dfs to explore all the paths and see if there are any ones
        //

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j);
                    max_area=max(area,max_area);
                }
            }
        }
        return max_area;

        
    }
};
