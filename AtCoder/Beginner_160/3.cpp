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
    
    ll k, n;
    cin >> k >> n;
    ll a[n];
    ll s = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> t;
    for(ll i=0;i<n;i++){
        if(i == 0){
            s+=(a[0] + k - a[n-1])%k;
            t.push_back((a[0] + k - a[n-1])%k);
        }
        else{
            s+=(a[i] - a[i-1] + k)%k;
            t.push_back((a[i] - a[i-1] + k)%k);
        }
    }
    // t.push_back((a[i] - a[i-1] + k)%k);
    sort(t.begin(), t.end(), greater<ll>());
    // for(ll i=0;i<t.size();i++){
    //     cout << t[i] << "\n";
    // }
    // cout << t[0] << "\n";
    cout << s - t[0] << "\n";

    return 0;
}