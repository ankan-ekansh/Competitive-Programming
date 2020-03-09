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
char a[201][201];
ll dp[201][201][2];
ll m, n;
bool valid(ll i, ll j){
    if(i >= 1 && i <= m && j>=1 && j <= n){
        return true;
    }
    return false;
}
ll fun(ll i, ll j, ll s){
    if(!valid(i, j)){
        return 0;
    }
    // cout << i << " " << j << " " << a[i][j] << " " <<  s << "\n";
    if(dp[i][j][s] != -1){
        return dp[i][j][s];
    }
    if(s == 1 && j == n && i == m){
        if(a[i][j] == '#'){
            return 0;
        }
        if(a[i][j] == '0'){
            return 0;
        }
        if(a[i][j] == 'T'){
            return 1;
        }
    }
    if(s == 0 && j == 1 && i == m){
        if(a[i][j] == '#'){
            return 0;
        }
        if(a[i][j] == '0'){
            return 0;
        }
        if(a[i][j] == 'T'){
            return 1;
        }
    }
    if(valid(i, j)){
        if(a[i][j] == 'T'){
            // return dp[i][j][s] = max(dp[i][j][s], max(1 + fun(i, j+1, s), 1 + fun(i+1, j, 1-s)));
            if(s == 1){
                return dp[i][j][s] = max(dp[i][j][s], max(1 + fun(i, j+1, s), 1 + fun(i+1, j, 1-s)));
            }
            else{
                return dp[i][j][s] = max(dp[i][j][s], max(1 + fun(i, j-1, s), 1 + fun(i+1, j, 1-s)));
            }
        }
        if(a[i][j] == '0'){
            if(s == 1){
                return dp[i][j][s] = max(dp[i][j][s], max(fun(i, j+1, s), fun(i+1, j, 1-s)));
            }
            if(s == 0){
                return dp[i][j][s] = max(dp[i][j][s], max(fun(i, j-1, s), fun(i+1, j, 1-s)));
            }
        }
        if(a[i][j] == '#'){
            return 0;
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
 
        cin >> m >> n;
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                cin >> a[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        // if(a[1][1] == '#'){
        //     cout << "0\n";
        //     continue;
        // }
        // else{
            ll ans = fun(1, 1, 1);
            // cout << dp[1][1][1] << "\n";
            // for(ll s=0;s<=1;s++){
            //     for(ll i=1;i<=m;i++){
            //         for(ll j=1;j<=n;j++){
            //             cout << dp[i][j][s] << " ";
            //         }
            //         cout << "\n";
            //     }
            //     cout << "\n\n";
            // }
            cout << ans << "\n";

        // }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}