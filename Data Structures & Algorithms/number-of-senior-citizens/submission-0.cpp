class Solution {
public:
    int countSeniors(vector<string>& details) {
        //so return the number of passengers > 60
        int count=0;
        for(auto detail: details){
            string res=detail.substr(11,2);
            if(stoi(res)>60) count++;
        }
        return count;
        
    }
};