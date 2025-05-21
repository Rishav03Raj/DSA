class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        for i in range(len(s)):
            s1 = s[:i+1]
            s1r = s1[::-1]
            s2 = s[i+1:]
            s2r = s2[::-1]
            st = s1r+s2r
            stre = st[::-1]
            print(stre)
            if stre== goal:
                return True

        return False

        