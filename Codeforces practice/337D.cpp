/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100007;
const ll inf = 0x3f3f3f3f;
ll n, m, d;
vector<ll> g[N], in(N), out(N);
vector<bool> bad(N);
void dfsin(ll u, ll p){
    if(bad[u]){
        in[u] = 0;
    }
    else{
        in[u] = -inf;
    }
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        dfsin(v, u);
        in[u] = max(in[u], 1 + in[v]);  //  1 + max(among children of u)
    }
}
void dfsout(ll u, ll p){
    ll mx1(-inf), mx2(-inf);
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        if(in[v] >= mx1){
            mx2 = mx1;
            mx1 = in[v];
        }
        else if(in[v] > mx2){
            mx2 = in[v];
        }
    }
    ll use;
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        if(in[v] == mx1){
            use = mx2;
        }
        else{
            use = mx1;
        }
        out[v] = max(2 + use, 1 + out[u]);
        if(bad[v] && out[v] < 0){
            out[v] = 0;
        }
        dfsout(v, u);
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
    
    cin >> n >> m >> d;
    for(ll i=0;i<m;i++){
        ll x;
        cin >> x;
        bad[x] = true;
    }
    for(ll i=0;i<n-1;i++){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsin(1, 0);
    if(bad[1]){
        out[1] = 0;
    }
    else{
        out[1] = -inf;
    }
    dfsout(1, 0);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(in[i] <= d && out[i] <= d){
            ans++;
        }
    }
    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}