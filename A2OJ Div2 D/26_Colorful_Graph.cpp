/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, mxmc;
map<int, int> adj[100007];
int color[100007];
int sz[100007];
int ans = 100007, s = 0;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> color[i];
    }
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        if(color[u] != color[v]){
            if(adj[color[u]].find(color[v]) == adj[color[u]].end()){
                adj[color[u]][color[v]] = 1;
                sz[color[u]]++;
            }
            if(adj[color[v]].find(color[u]) == adj[color[v]].end()){
                adj[color[v]][color[u]] = 1;
                sz[color[v]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(sz[color[i]] > s || (sz[color[i]] == s && color[i] < ans)){
            s = sz[color[i]];
            ans = color[i];
        }
    }
    cout << ans << "\n";
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}