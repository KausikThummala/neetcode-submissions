void swap(int *a,int *b);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first take the transpose and then reverse the rows
        //transpose
        //when taking the transpose
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
        //now to reverse the rows
       
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

        
    }
};
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
