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
ll n, q, root;
ll property[100007];
vector<ll> adj[100007];
// vector<ll> tin, tout, depth;
// vector<vector<ll>> par;
ll tin[100007], tout[100007], depth[100007], par[100007][20];
ll timer = 0;
void dfs(ll u = root, ll p = root, ll d = 0){
    tin[u] = ++timer;
    par[u][0] = p;
    depth[u] = d;
    for(ll i=1;i<=(ll)(ceil(log2(n)));i++){
        par[u][i] = par[par[u][i-1]][i-1];
    }
    for(ll v : adj[u]){
        if(v == p){
            continue;
        }
        depth[v] = d + 1;
        dfs(v, u, d + 1);
    }
    tout[u] = ++timer;
}
bool isAncestor(ll u, ll v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v){
    if(isAncestor(u, v)){
        return u;
    }
    if(isAncestor(v, u)){
        return v;
    }
    for(ll i=(ll)(ceil(log2(n)));i>=0;i--){
        if(!isAncestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}
void query(ll t, ll u, ll v){
    if(t == 1){
        ll ancestor = lca(u, v);
        property[u] += depth[u] - depth[ancestor];
        property[v] += depth[v] - depth[ancestor];
    }
    else{
        if(property[u] == property[v]){
            cout << "0\n";
        }
        else{
            // cout << max(property[u], property[v]) << "\n";
            if(property[u] > property[v]){
                cout << u << "\n";
            }
            else{
                cout << v << "\n";
            }
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
    

    cin >> n >> q;
    cin >> root;
    // tin.assign(n+7, 0);
    // tout.assign(n+7, 0);
    // depth.assign(n+7, 0);
    // par.assign(n+7, vector<ll>(ceil(log2(n))));
    for(ll i=1;i<=n;i++){
        cin >> property[i];
    }
    for(ll i=1;i<n;i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    while(q--){
        ll t, u, v;
        cin >> t >> u >> v;
        query(t, u, v);
    }
    // tin.clear();
    // tout.clear();
    // depth.clear();
    // par.clear();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}