def wordscubes(word, b, h,answer,cubes):
    if len(word)-1 == int(h):
        for i in range(len(answer)):
            Fout.write(str(answer[i]))
            Fout.write(' ')
            Fout.close() 
            Fin.close()
        #Fout.writelines(str(*(answer)))
        exit(0)
    for i in range(len(cubes)):
        if b[i] == 0:
            b[i] = 1
            if str(cubes[i]).find(word[h]) != -1:
                answer.append(i + 1)
                wordscubes(word, b, int(h)+1,answer,cubes)
                answer.pop()
            b[i] = 0

Fin = open ("brute_force\input.txt" ) 
Fout = open ("brute_force\output.txt", "w" )

n = Fin.readline()
word = Fin.readline()
cubes = []
answer = []
b = [0] * int(n)
for i in range(int(n)):
    cubes.append(Fin.readline().split())
wordscubes(word, b, 0,answer,cubes)
Fout.write('0')

