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
bool comp(pair<ll, ll> p, pair<ll, ll> q){
    return ((p.first + p.second) < (q.first + q.second));
}
bool comp2(pair<ll, ll> p, pair<ll, ll> q){
    return p.second < q.second;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    ll x = 0, y = 0;
    ll s = LLONG_MAX;
    ll xm = LLONG_MAX, ym = LLONG_MAX;
    ll c = LLONG_MAX;
    vector<pair<ll, ll>> v;
    for(y=0;y<=(n/7);y++){
        x = (n - 7*y)/4;
        if(4*x + 7*y == n){
            v.push_back({x, y});
        }
    }
    sort(v.begin(), v.end(), comp);
    vector<pair<ll, ll>> w;
    for(auto p : v){
        // cout << p.first << " " << p.second << "\n";
        if(p.first + p.second == v[0].first + v[0].second){
            w.push_back(p);
        }
    }
    sort(w.begin(), w.end(), comp2);
    // for(auto p : w){
    //     cout << p.first << " " << p.second << "\n";
    // }
    if(w.size() == 0){
        cout << "-1\n";
        exit(0);
    }
    for(int i=0;i<w[0].first;i++){
        cout << "4";
    }
    for(int i=0;i<w[0].second;i++){
        cout << "7";
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}