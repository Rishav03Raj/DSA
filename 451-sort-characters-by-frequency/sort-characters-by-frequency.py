class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dic = {}
        for c in s:
            dic[c] = dic.get(c, 0) + 1  # cleaner counting

        # Sort the dictionary items by frequency descending
        dic = (sorted(dic.items(), key=lambda x: x[1], reverse=True))

        # Build final string using string multiplication
        res = ""
        for char in dic:
            res += char[0]*char[1]

        return res
