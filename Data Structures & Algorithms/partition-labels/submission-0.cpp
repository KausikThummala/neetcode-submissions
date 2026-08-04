class Solution {
public:
    vector<int> partitionLabels(string s) {
        //here use a vector
        vector<int> ans;
        //use a hashmap to map the characters to its last occurence
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        //after making a hashmap
        int st=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,mpp[s[i]]);
            if(i==end){
                ans.push_back(end-st+1);
                st=i+1;
            }
        }
        return ans;
        
    }
};
