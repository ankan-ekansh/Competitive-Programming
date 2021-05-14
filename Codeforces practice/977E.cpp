#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> adj[200007];
vector<int> indeg(200007), outdeg(200007);
vector<bool> vis(200007);
int n, m;
void dfs(int u, bool &ok){
    // if(indeg[u] != -1 || outdeg[u] != -1){
    //     ok &= false;
    // }
    if(adj[u].size() != 2){
        ok &= false;
    }
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, ok);
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
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=1;i<=n;i++){
    //     for(int x : adj[i]){
    //         indeg[x]++;
    //     }
    //     outdeg[i]++;
    // }
    int ans = 0;
    for(int i=1;i<=n;i++){
        // cout << i << " " << indeg[i] << " " << outdeg[i] << "\n";
        bool ok = true;
        if(!vis[i]){
            dfs(i, ok);
            if(ok){
                ans++;
            }
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}