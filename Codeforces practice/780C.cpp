/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 7;
int n;
int maxDeg;
vector<int> g[N];
vector<int> color(N, -1);
void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int u, int p){
    int i=0, j=1;
    while(i < g[u].size()){
        if(j == color[u] || j == color[p]){
            j++;
            continue;
        }
        if(color[g[u][i]] == -1){
            color[g[u][i]] = j;
            j++;
        }
        i++;
    }
    for(ll v : g[u]){
        if(v == p){
            continue;
        }
        dfs(v, u);
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
        addEdge(u, v);
    }
    for(int i=1;i<=n;i++){
        maxDeg = max(maxDeg, (int)g[i].size());
    }
    maxDeg++;
    color[1] = 1;
    dfs(1, 0);
    cout << maxDeg << "\n";
    for(ll i=1;i<=n;i++){
        cout << color[i] << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}