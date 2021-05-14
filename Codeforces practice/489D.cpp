/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
vector<vector<ll>> adj;
vector<ll> cnt;
vector<bool> vis;
// void dfs(ll u, ll d = 0){
//     if(d == 2){
//         cnt[u]++;
//         return;
//     }
//     for(ll v : adj[u]){
//         dfs(v, d+1);
//     }
// }
void bfs(ll s){
    vector<ll> dis(n+7, 0);
    dis[s] = 0;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        if(dis[u] > 2){
            break;
        }
        for(ll v : adj[u]){
            dis[v] = dis[u] + 1;
            if(dis[v] == 2){
                cnt[v]++;
                continue;
            }
            q.push(v);
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
    adj.resize(n+7, vector<ll>());
    cnt.resize(n+7, 0);
    vis.resize(n+7, false);
    for(ll i=0;i<m;i++){
        ll u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    // for(ll i=1;i<=n;i++){
    //     cout << i << " - ";
    //     for(ll j : adj[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        cnt.assign(n+7, 0);
        bfs(i);
        // dfs(i);
        // cout << "\n";
        // cout << i << " = ";
        // for(ll j=1;j<=n;j++){
        //     cout << cnt[j] << ", ";
        // }
        // cout << "\n";
        for(ll j=1;j<=n;j++){
            if(i == j){
                continue;
            }
            ans += (cnt[j] * (cnt[j] - 1))/2;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}