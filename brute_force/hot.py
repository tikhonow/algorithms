#!/usr/bin/env python
from __future__ import print_function
import re
def bind(char_used, words, h):
    int(h)
    if len(words) == int(h):
        raise SystemExit(1)
    for i in range(len(str(*(words[h])))):
        a = str(words[h])
        reg = re.compile('[^a-zA-Z ]')
        a = reg.sub('', a)
        

        index = ord(str(a[i]))
        if char_used[index] == 0:
            char_used[index] += 1
            for j in range(0,i):
                print(a[j],end='')
            print("&",end='')
            for j in range(i,len(str(*(words[h])))):
                print(a[j],end='')
            print('\n',end='')
            bind(char_used, words,int(h) +1)

        if i+1 == len(str(*(words[h]))):
            print(str(*(words[h])),end='\n')
            bind(char_used, words,int(h) +1)
            
n = int(input())
words, used, char_used =[], [0]*n,[0]*256
for i in range(n):
    words.append(input().split())
bind(char_used, words,0)


            
            


