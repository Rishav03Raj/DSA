class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split()
        s = ""
        
        for i in range(len(l)-1,-1,-1):
            s+=l[i]
            if i!=0:
                s+=' '
        return s