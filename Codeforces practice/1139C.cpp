#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const ll N = 1e5+7;
ll n, k;
vector<ll> adj[N];
vector<bool> vis(N);
ll modexp(ll a, ll b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a % mod;
    }
    else{
        ll x = modexp(a, b/2);
        if(b % 2 == 0){
            return (x*x)%mod;
        }
        else{
            return (((a*x)%mod)*x)%mod;
        }
    }
}
void dfs(ll u, ll &c){
    vis[u] = true;
    c++;
    for(ll v : adj[u]){
        if(!vis[v])
            dfs(v, c);
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
    
    cin >> n >> k;
    for(ll i=1;i<n;i++){
        ll u, v, e;
        cin >> u >> v >> e;
        if(!e){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    ll ans = modexp(n, k);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            ll tmp = 0;
            dfs(i, tmp);
            ans = (ans - modexp(tmp, k))%mod;
        }
    }
    if(ans < 0){
        ans += mod;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}