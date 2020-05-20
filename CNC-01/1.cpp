#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000039
long long mul(long long a, long long b){
    return ((a % mod) * (b % mod)) % mod;
}
long long power(long long a, long long b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a % mod;
    }
    else{
        long long x = power(a, b/2);
        if(b % 2 == 0){
            return mul(x, x);
        }
        else{
            return mul(x, mul(x, a));
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        long long k, n;
        cin >> k >> n;
        if(k >= n){
            cout << n % mod << "\n"; 
        }
        else{
            long long x = n / k;
            long long y = n % k;
            long long ans = (mul(k - y, power(mul(n, power(k, mod-2)), 2)) + (mul(y, power(mul(n, power(k, mod-2)) + 1, 2))));
            cout << ans % mod << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}