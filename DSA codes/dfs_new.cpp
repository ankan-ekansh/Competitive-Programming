#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n;
vector<bool> vis;

void dfs(int v){
    vis[v]=true;
    for(int u : adj[v]){
        if(!vis[u]){
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

    int h,w;
    cin>>h>>w;
    n = h*w;
    if(h == 0 && w == 0){
        exit(0);
    }
    int ans=0;


    cout<<

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}