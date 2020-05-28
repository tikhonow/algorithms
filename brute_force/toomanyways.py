import math
with open('input.txt') as f:
    xm,ym,zm,xb,yb,zb = [int(x1) for x1 in f.readline().split()]
x, y, z = abs(xm-xb),abs(ym-yb), abs(zm-zb)
f2 = open('output.txt','w')
number_of_ways = int(math.factorial(x+y+z) // (math.factorial(x)*math.factorial(y)*math.factorial(z)))%int(1000000007)
f2.write(str(int(number_of_ways)))