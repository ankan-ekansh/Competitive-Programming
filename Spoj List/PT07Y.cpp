#include<bits/stdc++.h>
using namespace std;
void dfs(int u, bool vis[], vector<int> adj[]){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, vis, adj);
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
 
        int n, m;
        cin >> n >> m;
        vector<int> adj[n+1];
        for(int i=1;i<=m;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(m == (n-1)){
            int c = 0;
            bool vis[n+1];
            memset(vis, 0, sizeof(vis));
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    dfs(i, vis, adj);
                    c++;
                }
            }
            if(c == 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "NO\n";
        }
 
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}