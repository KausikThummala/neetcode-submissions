class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=(m*n)-1;
        int i=0;
        int j=0;
        while(l<=r){
            int mid=(l+(r-l)/2);
            i=mid/n;
            j=mid%n;
            if(matrix[i][j]>target){
                r=mid-1;
            }
            else if(matrix[i][j]<target){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;

        
    }
};
