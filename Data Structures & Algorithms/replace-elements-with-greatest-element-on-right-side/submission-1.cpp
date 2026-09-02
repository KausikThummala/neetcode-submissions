class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //
        if(arr.size()==1) return {-1};
        vector<int> ans(arr.size(),-1);
        //iterate from right to left and use a stack here
        int greatest=arr[arr.size()-1];
        ans[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i+1]>greatest){
                greatest=arr[i+1];
            }
            ans[i]=greatest;
        }
        return ans;
        
    }
};