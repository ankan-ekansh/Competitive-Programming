#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
bool prime[1000007];
void sieve(){
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(ll i=2;i*i<=1000000;i++){
        if(prime[i]){
            for(ll j=i*i;j<=1000000;j+=i){
                prime[j] = false;
            }
        }
    }
}
ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // sieve();
    // for(ll i=2;i<=20;i++){
    //     if(prime[i]){
    //         cout << i << " ";
    //     }
    // }
    ll t;
    // cin >> t;
    t = 1;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            cout << "1\n";
            continue;
            // return 0;
        }
        ll l = lcm(n , (n-1));
        ll ans = l;
        // ll g = __gcd(n, n-1);
        for(ll i=n-2;i>=1;i--){
            // if(prime[i] && n % i != 0 && (n-1) % i != 0){
                ans = max(ans, lcm(l, i));
                // break;
            // }
        }
        for(ll i=n;i>=3;i--){
            ans = max(ans, lcm(i, lcm(i-1, i-2)));
        }
        cout << ans << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}