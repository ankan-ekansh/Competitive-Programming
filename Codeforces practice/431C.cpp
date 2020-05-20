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
ll mod = 1000000007;
ll dp[107][2];
ll dfs(ll n, ll k, ll d, ll sum, bool include){
    ll ans = 0;
    if(sum > n){
        return 0;
    }
    if(sum == n){
        // dp[sum][include] = include;
        return dp[sum][include] = include;
    }
    for(ll i=1;i<=k;i++){
        if((sum + i) > n){
            break;
        }
        bool now_include = false;
        if(include || (i >= d)){
            now_include = true;
        }
        if(dp[sum+i][now_include] == -1){
            ans+=dfs(n, k, d, sum+i, now_include)%mod;
        }
        else{
            ans+=dp[sum+i][now_include]%mod;
        }
    }
    dp[sum][include] = ans;
    return dp[sum][include];
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
    ll n, k, d;
    cin >> n >> k >> d;
    bool include = false;
    ll ans = 0;
    ans = dfs(n, k, d, 0, include);
    cout << ans % mod << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}