#include<bits/stdc++.h>
using namespace std;
//vector<vector<int>> adj(10, vector<int> (10));
//vector<vector<int>> adj(100050);
//vector<bool> vis(10);
// vector<int> adj;
vector<vector<int>> adj;
vector<bool> vis;
int vno;
void dfs(int v){
    vis[v] = true;
    //cout<<v<<"\n";
    for(int u : adj[v]){
        if(!vis[u]){
            //vno++;
            dfs(u);
        }
    }
    // int u = adj[v];
    // if(!vis[u]){
    //     vno++;
    //     dfs(u);
    // }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int n;
        cin>>n;
        adj.resize(n+50);
        vis.resize(n+50);
        int e;
        cin>>e;
        int f = e;
        int x,y;

        if(f>0){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            // adj[x]=y;
            // adj[y]=x;
            f--;
        }
        while(f-- > 0){
            int v,u;
            cin>>v>>u;
            adj[v].push_back(u);
            adj[u].push_back(v);
            // adj[v]=u;
            // adj[u]=v;
        }
        // dfs(x);
        for(int i=0;i<n;i++){
            // vector<int> vt = adj[i];
            // cout<<i<<" : ";
            // for(int x : vt){
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            //if(vt.size()!=0)
            if(vis[i] == false){
                dfs(i);
                vno++;
            }
            //dfs(i);
        }
        //cout<<n-vno+1<<"\n";
        //cout<<"\n"<<vno<<"\n\n";
        // if(vno != 0)
        //     cout<<vno<<"\n";
        // else
        cout<<vno<<"\n";
        vno = 0;
        adj.clear();
        vis.clear();
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}