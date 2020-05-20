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
ll n, k;
string s;
map<char, ll> m;
vector<bool> vis;
vector<ll> adj[200007];
void dfs(ll &src, ll &sz){
    vis[src] = true;
    sz++;
    m[s[src]]++;
    for(ll v : adj[src]){
        if(!vis[v]){
            dfs(v, sz);
        }
    }
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
 
        cin >> n >> k;
        cin >> s;
        m.clear();
        vis.clear();
        vis.resize(n+7);
        for(ll i=0;i<n;i++){
            if(i+k < n){
                adj[i].push_back(i+k);
                adj[i+k].push_back(i);
            }
            if(i < n-1-i){
                adj[i].push_back(n-1-i);
                adj[n-1-i].push_back(i);
            }
        }
        ll ans = 0;
        for(ll i=0;i<n;i++){
            if(!vis[i]){
                m.clear();
                ll sz = 0;
                dfs(i, sz);
                ll ctr = 0;
                for(auto p : m){
                    ctr = max(ctr, p.second);
                }
                ans += sz - ctr;
            }
        }
        m.clear();
        s.clear();
        for(ll i=0;i<n;i++){
            adj[i].clear();
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}