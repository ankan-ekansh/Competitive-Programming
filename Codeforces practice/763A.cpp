/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> adj[100007];
vector<int> col(100007);
bool dfs(int u, int p, int c, bool &ok){
    if(col[u] != c){
        return ok &= false;
    }
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u, c, ok);
        }
    }
    return ok &= true;
}
bool func(int u){
    bool res = true;
    for(auto v : adj[u]){
        bool ok = true;
        dfs(v, u, col[v], ok);
        res &= ok;
    }
    return res;
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
        cin >> col[i];
    }
    int r1 = -1, r2 = -1;
    for(int i=1;i<=n;i++){
        for(auto u : adj[i]){
            if(col[u] != col[i]){
                r1 = u, r2 = i;
            }
        }
    }
    if(r1 == -1){
        cout << "YES\n1\n";
        return 0;
    }
    bool res1 = func(r1);
    bool res2 = func(r2);
    if(res1){
        cout << "YES\n";
        cout << r1 << "\n";
    }
    else if(res2){
        cout << "YES\n";
        cout << r2 << "\n";
    }
    else{
        cout << "NO\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}