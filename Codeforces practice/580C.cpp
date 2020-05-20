#include<bits/stdc++.h>
using namespace std;
int n, m;
bool vis[100007];
vector<int> adj[100007];
int no[100007];
int cat[1000007];
int ans;
void dfs(int x){
    vis[x] = true;
    if(adj[x].size() == 1 && vis[adj[x][0]]){
        cout << "Leaf node at " << x << "\n";
        if(no[x] <= m){
            cout << no[x] << " : " << x << "\n";
            ans++;
        }
    }
    for(int u : adj[x]){
        if(!vis[u]){
            // cout << u << "\n";
            if(cat[u] && cat[x]){
                no[u] = no[x] + 1;
            }
            else{
                no[u] = 0;
            }
            if(no[u] <= m)
                dfs(u);
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
        no[1] = 1;
    }
    dfs(1);
    // for(int i=1;i<=n;i++){
    //     for(int u : adj[i]){
    //         cout << u << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=1;i<=n;i++){
        cout << no[i] << "\n";
    }

    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}