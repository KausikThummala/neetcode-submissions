#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //here you need to keep a set
        set <int> s1;
        int length=0;
        int max_length=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            while(s1.find(s[r]) != s1.end()){
                s1.erase(s[l]);
                l+=1;
            }
            length=r-l+1;
            max_length=max(max_length,length);
            s1.insert(s[r]);
        }
        return max_length;


        
    }
};
