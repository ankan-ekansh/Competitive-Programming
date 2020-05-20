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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll dp[n+7][3];      // 0 sleep, 1 gym, 2 code
    // memset(dp, 1000, sizeof(dp));
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<3;j++){
            dp[i][j] = 1000;
        }
    }
    dp[1][0] = 1;
    if(a[1] == 1){
        dp[1][2] = 0;
    }
    if(a[1] == 2){
        dp[1][1] = 0;
    }
    if(a[1] == 3){
        dp[1][1] = dp[1][2] = 0;
    }
    // if(n == 1){
    //     cout << min(dp[1][0], min(dp[1][1], dp[1][2])) << "\n";
    //     return 0;
    // }
    for(ll i=2;i<=n;i++){
        if(a[i] == 0){
            dp[i][0] = min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1);
        }
        if(a[i] == 1){
            dp[i][0] = min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1);
            dp[i][2] = min(dp[i][2], min(dp[i-1][0], dp[i-1][1]));
        }
        if(a[i] == 2){
            dp[i][0] = min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1);
            dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][2]));
        }
        if(a[i] == 3){
            dp[i][0] = min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1);
            dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][2]));
            dp[i][2] = min(dp[i][2], min(dp[i-1][0], dp[i-1][1]));
        }
    }
    cout << min(dp[n][0] , min(dp[n][1], dp[n][2])) << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}