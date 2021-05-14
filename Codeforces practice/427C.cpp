/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const ll N = 3e5+7;
ll n, m;
vector<ll> G[N];
vector<ll> G_rev[N];
vector<ll> cost(N);
vector<bool> vis_f(N), vis_b(N);
stack<ll> dfsorder;
void dfs_f(ll u){
    vis_f[u] = true;
    for(ll v : G[u]){
        if(!vis_f[v]){
            dfs_f(v);
        }
    }
    dfsorder.push(u);
}
pair<ll, ll> dfs_b(multiset<ll> &s, ll u){
    vis_b[u] = true;
    s.insert(cost[u]);
    for(ll v : G_rev[u]){
        if(!vis_b[v]){
            dfs_b(s, v);
        }
    }
    return {*s.begin(), s.count(*s.begin())};
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> cost[i];
    }
    cin >> m;
    for(ll i=1;i<=m;i++){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G_rev[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        if(!vis_f[i]){
            dfs_f(i);
        }
    }
    ll cost = 0, ways = 1;
    while(!dfsorder.empty()){
        ll s = dfsorder.top();
        dfsorder.pop();
        if(vis_b[s]){
            continue;
        }
        multiset<ll> st;
        pair<ll, ll> x;
        x = dfs_b(st, s);
        cost += x.first;
        ways = (ways * x.second)%mod;
    }
    cout << cost << " " << ways << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}