class Solution {
public:
    bool dfs(vector<vector<char>>& board,string & word,int index,int r,int c){

        if(index==word.size()){
            return true;
        }
        //if r and c are out of bounds i can return false
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()){
            return false;
        }
        if(word[index]!=board[r][c]) return false;
        //if the character at that index doesnt match the char at board[r][c]
        //then return false;
        char tmp=board[r][c];
        //after visiting that cell mark it
        board[r][c]='#';
        //explore all the possible paths
        bool found=dfs(board,word,index+1,r+1,c) || dfs(board,word,index+1,r-1,c) || dfs(board,word,index+1,r,c-1) || dfs(board,word,index+1,r,c+1);
        board[r][c]=tmp;
        //unmark that cell for other starting paths so that this paths can use this cell
        return found;



    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;

        
    }
};
