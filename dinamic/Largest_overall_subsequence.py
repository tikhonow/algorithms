fin  = open('input.txt', 'r').read().split('\n')         
fout = open('output.txt', 'w')
A, B = fin[0],fin[1]
n = len(A)
m = len(B)
sub_count = [[0] * (m + 1) for i in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if A[i - 1] == B[j - 1]:
            sub_count[i][j] = sub_count[i - 1][j - 1] + 1 
        else: 
            sub_count[i][j] = max(sub_count[i - 1][j], sub_count[i][j - 1]) 
sub = []
i = n
j = m
while i > 0 and j > 0:
    if A[i - 1] == B[j - 1]:
        sub.append(A[i - 1])
        i -= 1
        j -= 1
    elif sub_count[i - 1][j] == sub_count[i][j]:
        i -= 1 
    else: 
        j -= 1 
sub = sub[::-1]
fout.write(''.join(sub) )