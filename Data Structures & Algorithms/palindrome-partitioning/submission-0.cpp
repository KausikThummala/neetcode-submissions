class Solution {
public:
    bool isPalin(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string &s,vector<string> &path,int start,vector <vector<string>> &ans ){
        //base case if start==s.size() then append and return
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int end=start;end <s.size();end++){
            if(isPalin(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                backtrack(s,path,end+1,ans);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector <vector<string>> ans;
        vector <string> path;
        backtrack(s,path,0,ans);
        return ans;

        
    }
};
