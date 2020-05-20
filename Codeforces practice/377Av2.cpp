#include<bits/stdc++.h>
using namespace std;
int n, m, k, s;
char a[507][507];
bool vis[507][507];
bool check(int i, int j){
    if((i>=1 && i<=n) && (j>=1 && j<=m) && (a[i][j] == '.')){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int i, int j, int* no){
    vis[i][j] = true;
    (*no)++;
    if(*no == (s - k)){
        return;
    }
    if(check(i-1, j) && !vis[i-1][j]){
        // cout << " up\n";
        dfs(i-1, j, no);
    }
    if(*no == (s - k)){
        return;
    }
    if(check(i+1, j) && !vis[i+1][j]){
        // cout << " down\n";
        dfs(i+1, j, no);
    }
    if(*no == (s - k)){
        return;
    }
    if(check(i, j-1) && !vis[i][j-1]){
        // cout << " left\n";
        dfs(i, j-1, no);
    }
    if(*no == (s - k)){
        return;
    }
    if(check(i, j+1) && !vis[i][j+1]){
        // cout << " right\n";
        dfs(i, j+1, no);
    }
    if(*no == (s - k)){
        return;
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
    int no = 0;
    s = v.size();
    dfs(v[0].first, v[0].second, &no);
    // cout << no << "\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << vis[i][j] << " ";      
    //     }
    //     cout << "\n";
    // }
    for(int i = 0;i<v.size();i++){
        if(!vis[v[i].first][v[i].second]){
            a[v[i].first][v[i].second] = 'X';
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