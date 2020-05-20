#include<bits/stdc++.h>
using namespace std;
int n, m, ans, noc[100007], cat[100007];
bool vis[100007];
vector<int> adj[100007];
void dfs(int x){
    vis[x] = true;
    if(adj[x].size() == 1 && vis[adj[x][0]]){
        if(noc[x] <= m){
            // cout << x << " can be reached" << "\n";
            ans++;
        }
    }
    for(int u : adj[x]){
        if(!vis[u]){
            if(cat[x] && cat[u]){
                noc[u] = noc[x] + 1;
            }
            else if(!cat[x] && cat[u]){
                noc[u] = 1;
            }
            else{
                noc[u] = 0;
            }

            if(noc[u] <= m){
                dfs(u);
            }
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

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> cat[i];
    }
    for(int i=1;i<n;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(cat[1] == 1){
        noc[1] = 1;
    }
    dfs(1);

    // for(int i=1;i<=n;i++){
    //     cout << noc[i] << "\n";
    // }

    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}