class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        dic = {}
        for  c in s:
            if c not in dic:
                 dic[c]=1
            else :
                dic[c]+=1

        for  c in t:
           if c not in dic:
            return False
           dic[c]-=1

        for keys, value in dic.items():
            if value!=0:
                return False

        return True