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
// vector<vector<ll>> adj;
vector<ll> adj[100007];
vector<ll> color;
vector<bool> vis;
set<ll> s1, s2;
void addEdge(ll u, ll v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool bfs(ll s){
    vis[s] = true;
    color[s] = 1;
    queue<ll> q;
    q.push(s);
    s1.insert(s);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                color[v] = 1 - color[u];
                if(color[v]){
                    s1.insert(v);
                }
                else{
                    s2.insert(v);
                }
                q.push(v);
            }
            else{
                if(color[v] == color[u]){
                    return false;
                }
            }
        }
    }
    return true;
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
    // adj.resize(n+7, vector<ll>(n+7));
    color.resize(n+7);
    vis.resize(n+7);
    for(ll i=0;i<m;i++){
        ll u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    // for(ll i=1;i<=n;i++){
    //     cout << i << " : ";
    //     for(ll e : adj[i]){
    //         cout << e << " ";
    //     }
    //     cout << "\n";
    // }
    bool flag = true;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            flag &= bfs(i);
            // cout << i << " ";
            // cout << flag << "---\n";
        }
    }
    if(!flag){
        cout << "-1\n";
    }
    else{
        cout << s1.size() << "\n";
        for(ll x : s1){
            cout << x << " ";
        }
        cout << "\n";
        cout << s2.size() << "\n";
        for(ll x : s2){
            cout << x << " ";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}