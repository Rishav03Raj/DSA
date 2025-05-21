class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        lt = []
        for rw in range(len(matrix)):
            for cl in range(len(matrix[0])):
                if(matrix[rw][cl]==0):
                    lt.append((rw,cl))

        for i,j in lt:
            for ik in range (len(matrix[0])):
                matrix[i][ik]=0
            for jk in  range (len(matrix)):
                matrix[jk][j]=0
        