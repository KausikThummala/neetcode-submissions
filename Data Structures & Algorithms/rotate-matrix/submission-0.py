class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        #to rotate it clockwise we have to find the transpose and reverse the rows
        n=len(matrix)
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        #now to reverse the rows 
        for i in range(n):
            for j in range(n//2):
                matrix[i][n-1-j],matrix[i][j]=matrix[i][j],matrix[i][n-1-j]
        