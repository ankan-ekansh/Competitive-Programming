/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+7;
ll n, q;
vector<ll> a(N), g[N];
vector<ll> in(N, 0), out(N, 0);
void dfs1(ll u, ll p){
    in[u] = 0;
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        dfs1(v, u);
        in[u] = max(in[u], in[v] + max(0LL, a[v] - a[u]));
    }
}
void dfs2(ll u, ll p){
    ll mx1 = -1, mx2 = -1;
    ll down;
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        down = max(0LL, a[v] - a[u]);
        if(in[v] + down >= mx1){
            mx2 = mx1;
            mx1 = in[v] + down;
        }
        else if(in[v] + down > mx2){
            mx2 = in[v] + down;
        }
    }
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        down = mx1;
        ll up = max(0LL, a[v] - a[u]);
        if(in[v] + up == mx1){
            down = mx2;
        }
        up = max(0LL, a[u] - a[v]);
        out[v] = max(up + out[u], up + down);
        dfs2(v, u);
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
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n-1;i++){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    while(q--){
        ll x;
        cin >> x;
        cout << max(in[x], out[x]) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}