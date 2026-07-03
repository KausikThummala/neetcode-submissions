class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> freq(26,0);//the vector size is of 26 as there are 26 alphabets
        //so make sure to count the frequencies of each character in the string
        if(s.size() != t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            char c = s[i];
            freq[c-'a']++;
        }
        for(char c: t){
            freq[c-'a']--;
        }
        for(int x: freq){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};
