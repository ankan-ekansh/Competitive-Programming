#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> adj[1000007];
// vector<bool> valid(1000007);
// vector<int> dist(1000007);
bool valid[1000007];
int dist[1000007];
bool bfs(int x, int c){
    vector<bool> vis(1000007, 0);
    dist[x] = 0;
    vis[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u] > c){
            break;
        }
        if(valid[u] == true){
            // cout << u << "\n";
            valid[u] = false;
            return false;
        }
        for(int v : adj[u]){
            if(!vis[v]){
                dist[v] = dist[u] + 1;
                if(dist[v] <= c){
                    vis[v] = true;
                }
                q.push(v);
            }

        }
        valid[u] = true;
    }
    return true;
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
        memset(valid, 0, sizeof(valid));
        memset(adj, 0, sizeof(adj));
        memset(dist, 0, sizeof(dist));
        int n, m, r;
        cin >> n >> r >> m;
        for(int i=0;i<r;i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool flag = true;
        for(int i=0;i<m;i++){
            int x, c;
            cin >> x >> c;
            flag = bfs(x, c);
        }
        for(int i=1;i<=n;i++){
            if(valid[i] == false){
                flag = false;
                break;
            }
            //cout << valid[i] << "\n";
        }
        if(flag){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}