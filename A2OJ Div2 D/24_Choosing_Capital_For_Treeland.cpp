/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[200007];
vector<ll> indeg(200007), outdeg(200007);
vector<bool> vis(200007);
ll n;
ll ctr;
void dfs(ll s){
    vis[s] = true;
    for(ll u : adj[s]){
        if(!vis[u]){
            ctr++;
            dfs(u);
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
    
    cin >> n;
    for(ll i=1;i<n;i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    ll min_indeg = n-1;
    for(ll i=1;i<=n;i++){
        min_indeg = min(min_indeg, indeg[i]);
    }
    vector<ll> choice;
    for(ll i=1;i<=n;i++){
        if(indeg[i] == min_indeg){
            choice.push_back(i);
        }
    }
    for(auto x : choice){
        vis.assign(false, vis.size());
        ctr=1;
        dfs(x);
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}