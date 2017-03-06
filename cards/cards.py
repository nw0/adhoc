#!/usr/bin/env python3

def p4(f):
    if f == 0:
        s = "   -"
    else:
        s = "%.3f   " % f
    print("%s " % s[:4], end="")

rv = 1000
p = [[0. for i in range(1000)] for j in range(1000)]

for i in range(rv):
    for j in range(rv):
        if i == 0 and j == 0:
            p[i][j] = 0.
        elif i == 0:
            p[i][j] = max(0, p[i][j-1]-1)
        elif j == 0:
            p[i][j] = max(0, p[i-1][j] + 1)
        else:
            p[i][j] = max(0., i/(i+j) * (p[i-1][j]+1) + j/(i+j) * (p[i][j-1]-1))
        #p4(p[i][j])
    #print("")
'''
print("--")
for i in range(27):
    p4(p[i][i])
print("")

for i in range(27):
    if i == 0:
        p4(0)
    else:
        p4(p[i][i] - p[i-1][i-1])
print("")'''
print(p[999][999])
