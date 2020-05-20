import numpy as np

t = int(input()) # read a line with a single integer
for i in range(1, t + 1):
    n, m = [int(s) for s in input().split(" ")]
    if (m % n == 0):
        print("Case #{}: POSSIBLE".format(i))
        matrix = np.arange(1, n + 1)
        r = int(m / n)
        if(r == n): 
            factor = r - 1
        else:
            factor = r
        arr = []
        for j in range(1, n + 1):
            s = r
            tmp = []
            for k in range(1, n + 1):
                tmp.append(s)
                s = s + 1
                if (s > n):
                    s = 1
            arr.append(tmp)
            print(' '.join(map(str, tmp)))
            r = r - 1
            if (r == 0):
                r = n
    else:
        print("Case #{}: IMPOSSIBLE".format(i))