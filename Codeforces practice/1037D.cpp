#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> adj[200007];
vector<int> dis(200007);
vector<bool> vis(200007);
vector<int> a(200007);
vector<int> b(200007);
vector<int> bfsorder, givenorder;
bool cmp(int u, int v){
    return b[u] < b[v];
}
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    // bfsorder.push_back(s);
    while(!q.empty()){
        int u = q.front();
        bfsorder.push_back(u);
        q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        givenorder.push_back(a[i]);
        b[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    bfs(1);
    // for(int x : givenorder){
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for(int x : bfsorder){
    //     cout << x << " ";
    // }
    // cout << "\n";
    if(givenorder == bfsorder){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}