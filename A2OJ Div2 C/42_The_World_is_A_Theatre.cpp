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
// ll f[31];
// void calcFac(){
//     f[0] = 1;
//     for(ll i=1;i<=30;i++){
//         f[i] = f[i-1] * i;
//     }
// }
ll nCr(ll n, ll r){
    // cout << f[n] << " " << f[n-r] * f[r] << "\n";
    // return f[n]/(f[n-r]*f[r]);
    ll C[n+1][r+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=min(i, r);j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
    }
    return C[n][r];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // calcFac();
    // for(ll i=1;i<=30;i++){
    //     cout << i << " " << f[i] << "\n";
    // }
    ll m, n, t;
    cin >> m >> n >> t;
    ll ans = 0;
    for(ll b = 4; b <= m; b++){
        if(t - b >= 1 && t - b <= n){
            ans += (nCr(m, b)*nCr(n, t-b));
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}