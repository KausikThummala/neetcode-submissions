class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #develop two hashmaps
        if len(s)!=len(t):
            return False
        seen={}
        for c in s:
            if c in seen:
                seen[c]+=1
            else:
                seen[c]=1
        for c in t:
            if c not in seen:
                return False
            elif seen[c]==1:
                del seen[c]
            elif seen[c]>1:
                seen[c]-=1
        return True
        