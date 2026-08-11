class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //now group the anagrams here
        //use a unordered_map here
        unordered_map<string,vector<string>> mpp;
        for(auto str: strs){
            string key=str;
            sort(key.begin(),key.end());
            mpp[key].push_back(str);
        }
        //now we need to get a 2d array of strings
        vector<vector<string>> ans;
        for(auto cell: mpp){
            auto vec=mpp[cell.first];
            ans.push_back(vec);
        }
        return ans;
    }
};
