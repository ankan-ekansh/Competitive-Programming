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
    int n, m;
    cin >> n >> m;
    bool adj[n+1][n+1];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        adj[x][y] = true;
        adj[y][x] = true;
    }
    int t;
    cin>>t;
    while(t--){
 
        int a, b;
        cin >> a >> b;
        if(adj[a][b]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}