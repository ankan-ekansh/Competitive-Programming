#include <bits/stdc++.h> 
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
vector<int> graph[100007]; 
vector<int> cycles[100007]; 
int color[100007], par[100007], mark[100007]; 
int cyclenumber = 0; 
int edges, nodes;
vector<bool> vis(100007);
void dfs_cycle(int u, int p){ 
    if(color[u] == 2) { 
        return; 
    }
    if(color[u] == 1){
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 
        while(cur != u){ 
            cur = par[cur]; 
            mark[cur] = cyclenumber; 
        } 
        return; 
    } 
    par[u] = p; 
    color[u] = 1; 
    for(int v : graph[u]){ 
        if(v == par[u]){ 
            continue; 
        } 
        dfs_cycle(v, u); 
    } 
    color[u] = 2; 
} 
void addEdge(int u, int v){ 
    graph[u].push_back(v); 
    graph[v].push_back(u); 
}
void dfs(int u){
    vis[u] = true;
    for(int v : graph[u]){
        if(!vis[v]){
            dfs(v);
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

    cin >> nodes >> edges;
    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    int components = 0;
    for(int i=1;i<=nodes;i++){
        if(!vis[i]){
            dfs(i);
            // cout << i << "\n";
            components++;
        }
    }
    // cout << components << "\n";
    if(components > 1){
        cout << "NO\n";
        return 0;
    }
    dfs_cycle(1, 0); 
    // cout << cyclenumber << "\n";
    if(cyclenumber > 1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }

    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
} 
