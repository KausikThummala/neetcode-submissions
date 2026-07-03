class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=0;
        int r=m*n-1;
        while(l<=r){
            int mid =l+((r-l)/2);
            i=(int)(mid/n);
            j=mid%n;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j] < target){
                l=mid+1;
            }
            else r=mid-1;
        }
        return false;

        
    }
};
