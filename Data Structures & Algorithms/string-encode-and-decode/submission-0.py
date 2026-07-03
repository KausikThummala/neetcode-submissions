class Solution:

    def encode(self, strs: List[str]) -> str:
        #we encode it using the length of the string and hashmap
        res=''
        for c in strs:
            res+=str(len(c))+"#"+c
        return res

    def decode(self, s: str) -> List[str]:
        #now decoding
        res,i=[],0
        while i<len(s):
            j=i
            while s[j]!='#':
                j+=1
            length=int(s[i:j])
            res.append(s[j+1:j+1+length])
            i=j+1+length
        return res
