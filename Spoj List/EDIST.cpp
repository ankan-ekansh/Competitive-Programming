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
ll dp[3000][3000];
string s1, s2;
ll fun(ll m, ll n){
    if(dp[m][n] != LLONG_MAX){
        return dp[m][n];
    }
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(s1[m-1] == s2[n-1]){
        return dp[m][n] = min(dp[m][n], fun(m-1, n-1));
    }
    else{
        return dp[m][n] = min(dp[m][n], min(1 + fun(m, n-1), min(1 + fun(m-1, n), 1 + fun(m-1, n-1))));
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
    ll t;
    cin>>t;
    while(t--){
 
        cin >> s1;
        cin >> s2;
        for(ll i=0;i<s1.length()+7;i++){
            for(ll j=0;j<s2.length()+7;j++){
                dp[i][j] = LLONG_MAX;
            }
        }
        ll ans = fun(s1.length(), s2.length());
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}