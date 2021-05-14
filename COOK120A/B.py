t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')[:n]))
    res = set() 
    pre = {0} 
    for x in a: 
        pre = {x | y for y in pre} | {x} 
        res |= pre 
    if(len(res) == n*(n+1)//2):
        print("YES")
    else:
        print("NO")