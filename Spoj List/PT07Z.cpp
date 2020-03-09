#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10007];
bool vis[10007];
int dist[10007];
int max_dist;
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dist[v] = dist[u] + 1;
            max_dist = max(max_dist, dist[v]);
            dfs(v);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int u, v;
    cin >> u >> v;
    int root = u;
    adj[u].push_back(v);
    adj[v].push_back(u);
    for(int i=2;i<n;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(root);
    // cout << "Root = " << root << "\n";
    for(int i=1;i<=n;i++){
        // cout << dist[i] << "\n";
        if(dist[i] == max_dist){
            root = i;
        }
    }
    // cout << max_dist << "\n";
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    dfs(root);
    cout << max_dist << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}