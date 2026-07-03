class Solution {
public:
    vector <string> mapping={
        " "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    void backtrack(string & digits,string &curr,vector <string> & ans,int index){
        if(index==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters =mapping[digits[index]-'0'];
        for(char ch:letters){
            curr.push_back(ch);
            backtrack(digits,curr,ans,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        string curr;
        if(digits.empty()) return ans;
        backtrack(digits,curr,ans,0);
        return ans;

        
    }
};
