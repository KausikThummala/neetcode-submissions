#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //here you need to keep a set
        unordered_set <char> st;
        int max_len=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l+=1;
            }
            st.insert(s[r]);
            max_len=max(r-l+1,max_len);
        }
        return max_len;
        
    }
};
