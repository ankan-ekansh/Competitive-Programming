#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define m 1000000007
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
ll fact[400007];

ll fun(ll n, ll r) {
    ll a = fact[n+r-1];
    ll b = fact[n];
    ll c = fact[r-1];
    b = modinv(b, m);
    c = modinv(c, m);
    return (((a * b) % m) * c) % m;
}
ll freq[200007];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fact[0] = 1;
    for(ll i=1;i<=400000;i++) {
        fact[i] = (fact[i-1] * i) % m;
    }
    ll n;
    cin >> n;
    multiset<ll> s;
    for(ll i=0;i<n;i++) {
        ll a, c;
        cin >> a >> c;
        freq[a]++;
        s.insert(a);
        ll x = distance(s.begin(), upper_bound(s.begin(), s.end(), a));
        cout << fun(c, x-1) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}