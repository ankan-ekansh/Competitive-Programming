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
ll n, m;
vector<ll> adj[100007];
vector<bool> vis(100007);
vector<ll> tin(100007), low(100007);
vector<pair<ll, ll>> edges;
// vector<pair<ll, ll>> bridges;
// vector<pair<ll, ll>> animals;
map<pair<ll, ll>, ll> bridge;
ll timer = 0;
void dfs(ll currentNode, ll parentNode){
    vis[currentNode] = true;
    tin[currentNode] = timer;
    low[currentNode] = timer;
    timer++;
    for(ll nextNode : adj[currentNode]){
        if(nextNode == parentNode){
            continue;
        }
        if(!vis[nextNode]){     //when neighbours are not visited
            dfs(nextNode, currentNode);
            low[currentNode] = min(low[currentNode], low[nextNode]);
            if(tin[currentNode] < low[nextNode]){
                // cout << currentNode << " " << nextNode << "\n";
                // bridges.push_back({currentNode, nextNode});
                // bridges.push_back({nextNode, currentNode});
                bridge[{currentNode, nextNode}]++;
                bridge[{nextNode, currentNode}]++;
            }
        }
        else{       //when neighbours are visited
            low[currentNode] = min(low[currentNode], tin[nextNode]);
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
    
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({x, y});
    }
    for (int i = 0; i < n; ++i){
        if(!vis[i])
            dfs(i, -1);
    }
    ll nA;
    cin >> nA;
    ll ans = 0;
    for(ll i=0;i<nA;i++){
        ll p;
        cin >> p;
        if(bridge[edges[p-1]]){
            ans++;
        }
    }
    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}