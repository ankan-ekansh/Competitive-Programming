#include<bits/stdc++.h>
using namespace std;
vector<int> adj[2007];
bool vis[2007];
int d[2007];
int ans = 0;
queue<int> q;
void bfs(int u){
    vis[u] = true;
    q.push(u);
    while(!q.empty()){
        int f = q.front();
        // cout << f << "\n";
        q.pop();
        for(int v:adj[f]){
            if(!vis[v]){
                vis[v] = true;
                d[v] = d[f] + 1;
                ans = max(ans, d[v]);
                q.push(v);
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

    int n;
    cin >> n;
    queue<int> r;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x != -1){
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        else{
            r.push(i);
        }
    }
    while(!r.empty()){
        int root = r.front();
        r.pop();
        bfs(root);
    }
    cout << ans+1 << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}