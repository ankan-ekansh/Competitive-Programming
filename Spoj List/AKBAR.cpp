#include<bits/stdc++.h>
using namespace std;
vector<long long> adj[1000007];
long long vis[1000007];
// long long dis[1000007];
void bfs(long long x, long long c){
    // bool vis2[1000007];
    // memset(vis2, false, sizeof(vis2));
    // memset(dis, 0, sizeof(dis));
    vector<long long> dis(1000007,0);
    vector<bool> vis2(1000007,false);
    vis2[x]=true;
    vis[x]++;
    queue<long long> q;
    q.push(x);
    while(!q.empty()){
        long long p = q.front();
        // cout << p << "\n";
        q.pop();
        for(long long v : adj[p]){
            // vis[v]++;
            // q.push(v);
            if(!vis2[v] && dis[p] < c){
                dis[v]=dis[p]+1;
                // cout << v << "\n";
                vis2[v] = true;
                vis[v]++;
                q.push(v);
            }
        }
        // cout << "\n";
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
    int t;
    cin>>t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));
        long long n, r, m;
        cin >> n >> r >> m;
        for(long long i=0;i<r;i++){
            long long x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(long long i=0;i<m;i++){
            long long x, c;
            cin >> x >> c;
            bfs(x, c);
        }
        bool flag = true;
        // for(int i=1;i<=n;i++){
        //     cout << i << ": " << vis[i] << "\n";
        // }
        for(int i=1;i<=n;i++){
            // cout << vis[i] << "\n";
            if(vis[i]!=1){
                flag = false;
                break;
            }
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