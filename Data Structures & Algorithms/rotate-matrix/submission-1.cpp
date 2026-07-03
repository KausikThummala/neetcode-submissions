void swap(int *a,int *b);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first take the transpose and then reverse the rows
        //transpose
        //when tanking the transpose
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
        //now to reverse the rows
       
        for(int i=0;i<n;i++){
            for(int j=0;j<(n/2);j++){
                swap(&matrix[i][j],&matrix[i][n-1-j]);
            }
        }

        
    }
};
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
