
t = int(input())
mod = int(1000000000039)
for i in range(t):
    k, n = map(int,input().split())
    x = n // k
    y = n % k
    if(k >= n):
        print(n%mod)
    else:
        ans = (((((k - y)%mod * ((x%mod))%mod) * (x%mod))%mod))%mod + (((y%mod * (x+1)%mod)%mod) * (x+1)%mod)%mod
        ans = ans % mod
        print(ans)