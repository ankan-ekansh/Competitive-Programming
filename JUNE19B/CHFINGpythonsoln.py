

t = int(input())
mod = int(1000000007)
inv_mod = int(500000004) 
for i in range(t):
    n,k = map(int,input().split())
    x = (k-1)//(n-1)
    ans = ((((k-1)*(x+1))%mod) - ((((((n-1)*(x))%mod)*(x+1))%mod)*(inv_mod))%mod)%mod
    print(ans)