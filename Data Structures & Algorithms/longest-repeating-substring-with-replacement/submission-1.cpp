class Solution {
public:
    int characterReplacement(string s, int k) {
        //here when the condtion is violated shrink the window
        int l=0;
        int max_freq=0;
        int max_len=0;
        vector<int> freq(26,0);
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            max_freq=max(max_freq,freq[s[r]-'A']);
            while((r-l+1)-max_freq>k){
                freq[s[l]-'A']--;
                l++;
            }
            max_len=max(max_len,r-l+1);

        }
        return max_len;
    }
};
