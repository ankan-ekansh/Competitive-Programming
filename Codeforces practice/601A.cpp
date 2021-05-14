#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
vector<int> road[407], rail[407];
vector<bool> vis(407);
vector<int> dist(407);
void bfsroad(){
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : road[u]){
            if(!vis[v]){
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void bfsrail(){
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : rail[u]){
            if(!vis[v]){
                vis[v] = true;
                dist[v] = dist[u] + 1;
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
    
    cin >> n >> m;
    bool railway = false;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        rail[u].push_back(v);
        rail[v].push_back(u);
        if((u == 1 && v == n) || (u == n && v == 1)){
            railway = true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                continue;
            }
            sort(rail[i].begin(), rail[i].end());
            if(!binary_search(rail[i].begin(), rail[i].end(), j)){
                road[i].push_back(j);
                // road[j].push_back(i);
            }
        }
    }
    // cout << "Rail \n";
    // for(int i=1;i<=n;i++){
    //     cout << i << " : ";
    //     for(int j : rail[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "Road \n";
    // for(int i=1;i<=n;i++){
    //     cout << i << " : ";
    //     for(int j : road[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    int ans = 0;
    if(railway){
        bfsroad();
        ans = dist[n];
        if(ans == 1 || ans == 0){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    else{
        bfsrail();
        ans = dist[n];
        if(ans == 1 || ans == 0){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}