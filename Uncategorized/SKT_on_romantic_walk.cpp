#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
long n;
    cin >> n;
    vector<long> adj[n+1];
    long dist[n+1];
    memset(dist, -1, sizeof(dist));
    for(long i=0;i<n-1;i++){
        long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(long i=0;i<n-1;i++){
        for(long j=0;j<adj[i].size();j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    queue<long> q;
    long start = 1;
    q.push(start);
    while(!q.empty()){
        long u = q.front();
        q.pop();
        start = u;
        for(long v:adj[u]){
            q.push(v);
        }
    }
    dist[start]+=1;
    q.push(start);
    while(!q.empty()){
        long u = q.front();
        q.pop();
        for(long v:adj[u]){
            q.push(v);
            dist[start]+=1;
        }
    }
    cout << dist[start] << "\n";
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}