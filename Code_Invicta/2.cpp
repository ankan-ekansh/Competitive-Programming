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
ll fun(ll n){
    ll pxa;
    ll rem = n % 4;
    if(rem == 0){
        pxa = n;
    }
    else if(rem == 1){
        pxa = 1;
    }
    else if(rem == 2){
        pxa = n+1;
    }
    else if(rem == 3){
        pxa = 0;
    }
    return pxa;
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
    
    // map<ll, set<ll>> l, r;
    set<ll> s0, s1;
    map<ll, ll> m;
    ll q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a == 1){
            m[b] = 1;
            s0.erase(b);
            if(s1.find(b+1) == s1.end()){
                s0.insert(b+1);
            }
            s1.insert(b);
        }
        else{
            // cout << b << " : ";
            ll x, y;
            if(s1.find(b) == s1.end()){
                x = b;
            }
            else{
                x = *s0.lower_bound(b);
            }
            auto i = s1.upper_bound(x);
            if(i == s1.end()){
                y = n;
            }
            else{
                y = *i - 1;
            }
            
            // cout << x << " " << y << "\n";
            cout << (fun(y) ^ fun(x-1)) << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}