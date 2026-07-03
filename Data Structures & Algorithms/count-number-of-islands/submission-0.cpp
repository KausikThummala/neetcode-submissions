class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        //out of bounds
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        //water or unvisited
        if(grid[i][j]=='0'){
            return;
        }
        //now set the grid[i][j] to0
        //to make sure it is visted

        grid[i][j]='0';
        //now explore in all 4 directions to see if their any neighboring ones
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    //after encountering a one count it and then call dfs
                    //to see if there are any neighbouring ones
                    dfs(grid,i,j);
                }
            }
        }
        return count;

        
    }
};
