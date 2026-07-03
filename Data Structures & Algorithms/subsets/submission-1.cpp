class Solution {
public:
    void dfs(vector <int> &nums,int index,vector<vector<int>> &ans,vector <int> &curr){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        //now add that element
        curr.push_back(nums[index]);
        //backtrack
        dfs(nums,index+1,ans,curr);
        //now pop_back
        curr.pop_back();
        dfs(nums,index+1,ans,curr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> curr;
        dfs(nums,0,ans,curr);
        return ans;

        
        
    }
};
