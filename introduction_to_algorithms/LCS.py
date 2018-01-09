def LCS_length(string1, string2):
	str1len = len(string1)
	str2len = len(string2)

	matrix1 = [[i - i for i in range(0, str2len + 1)]]*(str1len + 1)
	matrix2 = [[i - i for i in range(0, str2len + 1)]]*(str1len + 1)
	
	
	string1 = '0' + string1
	string2 = '0' + string2

	for i in range(1, str1len + 1 ):
		for j in range(1, str2len + 1):
			if string1[i] == string2[j]: # the line has a problem, 
			# the == should redefine, the == should express that the
			# string1[1:i] equal to  string2[1:j], also which has a 
			# max-LCS
				
				matrix2[i][j] = matrix2[i-1][j-1] + 1
				matrix1[i][j] = '<'
			elif matrix2[i-1][j] >= matrix2[i][j-1]:
				matrix2[i][j] = matrix2[i-1][j]
				matrix1[i][j] = '|'
			else:
				matrix2[i][j] = matrix2[i][j-1]
				matrix1[i][j] = '-'

	return matrix1, matrix2

def print_LCS(matrix1, string1, i, j):
	
	if i == 0 or j == 0:
		return 
	if matrix1[i][j] == '<':
		print_LCS(matrix1, string1, i-1, j-1)
		print(string1[i])
	elif matrix1[i][j] == '|':
		print_LCS(matrix1, string1, i-1, j)
	else:
		print_LCS(matrix1, string1, i, j-1)


#********************   main   ********************#

if __name__ == '__main__':
	string1 = 'ABCBDAB'
	string2 = 'DDCABA'
	matrix1, matrix2 = LCS_length(string1, string2)
	for i in range(0, len(string1) + 1):
		print(matrix1[i])
	string1 = '0' + string1
	print_LCS(matrix1, string1, len(string1)-1, len(string2))









