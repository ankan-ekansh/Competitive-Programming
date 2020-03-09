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
ll n;
ll dp[10000002][2];
// ll found[10000001][2];
ll mod = 1000000007;
// ll fun(ll sum, ll state){
//     if(sum == 0){
//         if(state){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(found[sum][state]){
//         return dp[sum][state];
//     }
//     if(state == 1){
//         return dp[sum][state] = 3LL*fun(sum-1, 1-state)%mod;
//     }
//     else{
//         return dp[sum][state] = ((2LL*fun(sum-1, state))%mod + (fun(sum-1, 1-state))%mod)%mod;
//     }
// }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // memset(dp, 0, sizeof(dp));
    cin >> n;
    // cout << fun(n, 1) << "\n";
    // for(ll i=0;i<=n;i++){
    //     cout << dp[i][0] << " " << dp[i][1] << "\n";
    // }
    dp[0][1] = 1;
    for(ll i=1;i<=n;i++){
        dp[i][1] = (3*dp[i-1][0])%mod;
        dp[i][0] = ((2*dp[i-1][0]) + (dp[i-1][1]))%mod;
    }
    cout << dp[n][1] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}