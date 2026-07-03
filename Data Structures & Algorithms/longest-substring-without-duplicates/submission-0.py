class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #here keep a set
        sett=set()
        l=0
        max_len=0
        for r in range(len(s)):
            while s[r] in sett:
                sett.remove(s[l])
                l+=1
            length=r-l+1
            max_len=max(length,max_len)
            sett.add(s[r])
        return max_len
        