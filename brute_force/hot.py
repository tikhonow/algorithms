import re
def bind(char_used, words, h):
    int(h)
    if len(words) == int(h):
        exit(0)
    for i in range(len(str(*(words[h])))):
        a = str(words[h])
        reg = re.compile('[^a-zA-Z ]')
        a = reg.sub('', a)
        index = ord(str(a[i]))
        if char_used[index] == 0:
            char_used[index] += 1
            for j in range(0,i):
                Fout.write(a[j])
            Fout.write('&')
            for j in range(i,len(str(*(words[h])))):
                Fout.write(str(a[j]))
            Fout.write('\n')
            bind(char_used, words,int(h) +1)

        if i+1 == len(str(*(words[h]))):
            Fout.write(str(*(words[h])))
            Fout.write('\n')
            bind(char_used, words,int(h) +1)
Fin = open ( "input.txt" ) 
Fout = open ( "output.txt", "w" )

n = int(Fin.readline())
words, used, char_used =[], [0]*n,[0]*256
for i in range(n):
    words.append(Fin.readline().split())
bind(char_used, words,0)
