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
ll nodes, edges;
vector<ll> adj[10007];
ll timer;
vector<ll> tin(10007), tout(10007);
vector<vector<ll>> par(10007, vector<ll>(20));
void dfs(ll currentNode = 1, ll parentNode = -1){
    tin[currentNode] = ++timer;
    par[currentNode][0] = parentNode;
    for(ll i=1;i<=(ll)(ceil(log2(nodes)));i++){
        par[currentNode][i] = par[par[currentNode][i-1]][i-1];
    }
    for(ll nextNode : adj[currentNode]){
        if(nextNode == parentNode){
            continue;
        }
        dfs(nextNode, currentNode);
    }
    tout[currentNode] = ++timer;
}
bool isAncestor(ll u, ll v){        // u is ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v){
    if(isAncestor(u, v)){
        return u;
    }
    if(isAncestor(v, u)){
        return v;
    }
    for(ll i = (ll)ceil(log2(nodes)); i>=0; i--){
        if(!isAncestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> nodes >> edges;
    for(int i=0;i<edges;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    ll q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << u << " " << v << " ";
        cout << lca(u, v) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}