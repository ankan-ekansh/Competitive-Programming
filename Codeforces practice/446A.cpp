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
    ll a[n+7], pref[n+7] = {0}, suff[n+7] = {0};
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    a[0] = 0, a[n+1] = LLONG_MAX;
    // for each i, find length of decreasing subarray starting from i towards left, and length of increasing subarray starting from i towards right
    for(ll i=1;i<=n;i++){
        if(a[i-1] < a[i]){
            pref[i] = pref[i-1] + 1;
        }
        else{
            pref[i] = 1;
        }
    }
    // cout << "  ";
    for(ll i=n;i>=1;i--){
        if(a[i] < a[i+1]){
            suff[i] = suff[i+1] + 1;
        }
        else{
            suff[i] = 1;
        }
    }
    // for(ll i=1;i<=n;i++){
    //     cout << suff[i] << " ";
    // }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans = max(ans, pref[i-1] + 1);
        ans = max(ans, suff[i+1] + 1);
        if(a[i+1] - a[i-1] >= 2){
            ans = max(ans, pref[i-1] + suff[i+1] + 1);
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}