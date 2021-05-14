#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[107];
vector<ll> a(107);
vector<ll> primes;
vector<ll> sz(107);
void dfs(ll u, ll p, ll d=1){
    // cout << u << " " << adj[u].size() << "\n";
    // sz[u] = 1;
    a[u] = d*(d+1);
    for(ll v : adj[u]){
        if(v == p){
            continue;
        }
        dfs(v, u, d+2);
        // assert(adj[u].size()-1 >= 0);
        // a[u] = primes[(ll)adj[u].size()-1] * a[v];
        // cout << primes.size() << "\n";
        // sz[u] = max(sz[u], sz[v]+1);
        // a[u] = primes[sz[u]-1] * a[v];
    }
}
void sieve(){
    bool p[107];
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for(ll i=2;i*i<=101;i++){
        if(p[i]){
            for(ll j=i*i;j<=101;j+=i){
                p[j] = false;
            }
        }
    }
    for(ll i=2;i<=101;i++){
        if(p[i]){
            primes.push_back(i);
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

    sieve();
    // cout << "---\n";
    // ll tst = 1;
    // for(ll i=0;i<=100;i++){
    //     if(primes[i] <= 100){
    //         cout << primes[i] << " ";
    //     }
    // }
    // cout << tst << "\n";
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;
        for(ll i=0;i<107;i++){
            a[i] = 1;
            sz[i] = 1;
        }
        for(ll i=0;i<=n;i++){
            adj[i].clear();
        }
        for(ll i=0;i<n-1;i++){
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        for(ll i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}