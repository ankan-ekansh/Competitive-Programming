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
ll a[2001];
ll dp[2001][2001];
ll n;
ll fun(ll i, ll j){
    // cout << i << " " << j << " " << t << "\n";
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll t = n - (j-i+1) + 1;
    if(i == j){
        return dp[i][j] = a[i] * t;
    }
    return dp[i][j] = max(fun(i+1, j) + a[i] * t, fun(i, j-1) + a[j] * t);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    // dp[1][n] = 0;
    ll ans = fun(1, n);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}