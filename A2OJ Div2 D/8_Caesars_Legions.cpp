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
ll dp[101][101][11][11];
ll n1, n2, k1, k2;
ll mod = 1e8;
ll fun(ll f, ll h, ll kf, ll kh){

    if(dp[f][h][kf][kh] == -1){
        dp[f][h][kf][kh] = 0;
        if((f + h) == 0){
            return dp[f][h][kf][kh] = 1;
        }
        else{
            if(f >= 1 && kf >= 1){
                dp[f][h][kf][kh] = (dp[f][h][kf][kh] + fun(f-1 ,h, kf-1, k2))%mod;
            }
            if(h >= 1 && kh >= 1){
                dp[f][h][kf][kh] = (dp[f][h][kf][kh] + fun(f, h-1, k1, kh-1))%mod;
            }
        }
    }
    return dp[f][h][kf][kh];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << fun(n1, n2, k1, k2) % mod << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}