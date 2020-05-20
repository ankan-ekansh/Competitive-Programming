#include<bits/stdc++.h>
using namespace std;
int n, m, k;
char a[507][507];
bool vis[507][507], t[507][507];
bool check(int i, int j){
    if((i>=1 && i<=n) && (j>=1 && j<=m) && (a[i][j] == '.')){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int i, int j){
    vis[i][j] = true;
    // cout << i << " " << j << "\n";
    if(check(i-1, j) && !vis[i-1][j]){
        // cout << " up\n";
        dfs(i-1, j);
    }
    if(check(i+1, j) && !vis[i+1][j]){
        // cout << " down\n";
        dfs(i+1, j);
    }
    if(check(i, j-1) && !vis[i][j-1]){
        // cout << " left\n";
        dfs(i, j-1);
    }
    if(check(i, j+1) && !vis[i][j+1]){
        // cout << " right\n";
        dfs(i, j+1);
    }
    else{
        return;
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

    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '.'){
                v.push_back(make_pair(i, j));
            }
        }
    }
    int nc = 0;
    int l = 1;
    while(l <= k){
        for(int x=0;x<v.size();x++){
            a[v[x].first][v[x].second] = 'X';
            nc = 0;
            l++;
            if(l > k){
                break;
            }
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=m;j++){
            //         cout << vis[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(!vis[i][j] && a[i][j] == '.'){
                        dfs(i, j);
                        // cout << "\n";
                        // cout << i << " " << j << "\n";
                        nc++;
                    }
                }
            }
            // cout << nc << " " << v[x].first << "," << v[x].second <<"\n";
            if(nc != 1){
                a[v[x].first][v[x].second] = '.';
                l--;
            }

            memset(vis, false, sizeof(vis));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}