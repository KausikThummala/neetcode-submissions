class Solution {
public:
    string minWindow(string s, string t) {
        //here use sliding window
        unordered_map<char,int> countT;
        if(t.empty() || t.size()>s.size()) return "";
        for(auto c: t) countT[c]++;
        unordered_map<char,int> window;
        int req=countT.size();
        int formed=0;
        int l=0;
        int start_idx=-1;
        int reslen=INT_MAX;
        for(int r=0;r<s.size();r++){
            window[s[r]]++;
            if(countT.count(s[r]) && window[s[r]]==countT[s[r]]){
                formed++;
            }
            while(formed==req){
                int size=r-l+1;
                if(size<reslen){
                    reslen=size;
                    start_idx=l;
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]]<countT[s[l]]){
                    formed-=1;
                }
                l++;

            }

        }
        return (start_idx==-1) ? "": s.substr(start_idx,reslen);
        
    }
};
