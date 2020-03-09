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
// ll *parent = new(nothrow) ll[1000000000];
// ll *sz = new(nothrow) ll[1000000000];
set<ll> lis;
vector<pair<ll, ll>> v;
map<ll, ll> parent;
map<ll, ll> sz;
multiset<ll, greater<ll>> s;
void make_set(ll a){
    parent[a] = a;
    sz[a] = 1;
    s.insert(1);
}
ll find_set(ll a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find_set(parent[a]);
    }
}
void union_set(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[b] > sz[a]){
            swap(a, b);
        }
        parent[b] = a;
        s.erase(s.find(sz[a]));
        s.erase(s.find(sz[b]));
        sz[a]+=sz[b];
        s.insert(sz[a]);
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
    
    ll n, m;
    cin >> n >> m;
    // for(ll i=1;i<=n;i++){
    //     make_set(i);
    // }
    for(ll i=1;i<=m;i++){
        ll a, b;
        cin >> a >> b;
        if(sz[a] == 0){
            make_set(a);
            lis.insert(a);
        }
        if(sz[b] == 0){
            make_set(b);
            lis.insert(b);
        }
        v.push_back(make_pair(a, b));
        // union_set(a, b);
    }
    for(ll i=0;i<v.size();i++){
        union_set(v[i].first, v[i].second);
    }
    cout << s.size() + (n - lis.size()) << "\n";
    // delete [] parent;
    // delete [] sz;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}