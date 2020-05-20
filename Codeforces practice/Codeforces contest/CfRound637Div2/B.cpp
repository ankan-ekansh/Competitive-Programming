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
    int t;
    cin>>t;
    while(t--){
 
        ll n, k;
        cin >> n >> k;
        ll a[n+7];
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        ll pf[n+7] = {0};
        for(ll i=2;i<=n-1;i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                pf[i]++;
            }
        }
        for(ll i=1;i<=n;i++){
            pf[i] = pf[i-1] + pf[i];
        }
        // for(ll i=1;i<=n;i++){
        //     cout << pf[i] << " ";
        // }
        // cout << "\n";
        ll ans = -1, idx = -1;
        for(ll i=1;i<=n-k+1;i++){
            // cout << i << " " << i+k-1 << " " << pf[i+k-1] << " " << pf[i] << "\n";
            if(pf[i+k-2] - pf[i] > ans){
                ans = max(ans, pf[i+k-2] - pf[i]);
                idx = i;
            }
        }
        cout << ans+1 << " " << idx << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}