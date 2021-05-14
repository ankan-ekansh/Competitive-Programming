#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100007];
vector<int> par(100007);
bool vis[100007];
vector<int> path(int node){
    int cur = node;
    vector<int> p;
    while(cur != -1){
        // cout << cur << " ";
        p.push_back(cur);
        cur = par[cur];
    }
    // cout << "\n";
    return p;
}
void dfs(int u, int p){
    par[u] = p;
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, u);
        }
    }
}
int main(){
    par[0] = -1;
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    for(int i=0;i<n;i++){
        vector<int> p = path(i);
        for(int x : p){
            cout << x << " ";
        }
        cout << "\n";
    }
}