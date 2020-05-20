def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
# import math
def lcm(a,b): 
    return (a*b) // gcd(a,b) 

def isPowerOfTwo(x): 
    return (x and (not(x & (x - 1))) ) 

n = int(input())
a = list(map(int,input().strip().split()))[:n]
# print(n)
# print(a)
l = a[0]
# for i in range(0, n):
#     l = lcm(l, a[i])
for x in a:
    l = lcm(l, x)
# print(l)
flag = True
for y in a:
    x = l//y
    if(isPowerOfTwo(x)):
        continue
    else:
        x = x - 1
        if(isPowerOfTwo(x)):
            continue
        else:
            flag = False
            break

if(flag == True):
    print("Yes")
else:
    print("No")
