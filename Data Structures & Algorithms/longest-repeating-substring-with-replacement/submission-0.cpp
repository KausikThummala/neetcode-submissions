class Solution {
public:
    int characterReplacement(string s, int k) {
        //maintain an vector of sixe 26
        int longest=0;
        int l=0;
        int maxFreq=0;
        vector <int> freq(26,0);
        for(int r=0;r<s.size();r++){
            maxFreq=max(maxFreq,++freq[(s[r]-'A')]);
            while(((r-l+1)-maxFreq)>k){
                freq[(s[l]-'A')]--;
                l+=1;
            }
            longest=max(longest,r-l+1);

        }
        return longest;
        
    }
};
