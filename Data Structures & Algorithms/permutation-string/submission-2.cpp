

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //to check permutation of string 
        //make two hashmaps
        if(s1.size() > s2.size()){
            return false;
        }
        int n=s1.size();
        vector <int> cnt1(26,0);
        vector <int> cnt2(26,0);
        //n is the window size
        for(char c: s1){
            cnt1[c-'a']++;
        }
        //first window
        for(int i=0;i<n;i++){
            cnt2[s2[i]-'a']++;
        }
        if(cnt1==cnt2){
            return true;
        }
        for(int i=n;i<s2.size();i++){
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-n]-'a']--;
            if(cnt1==cnt2){
                return true;
            }
        }
        return false;

    }
};
