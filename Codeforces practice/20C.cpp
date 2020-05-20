#include<bits/stdc++.h>
#define ll long long
#define INF 1000000000000000000
using namespace std;
ll n, m;
vector<ll> dist(100007, INF);
vector<pair<ll, ll>> adj[100007];
// ll parent[100007];
vector<ll> parent(100007, -1);
void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
    dist[s] = 0;
    parent[s] = -1;
    pq.push({0, s});
    while(!pq.empty()){
        pair<ll, ll> p = pq.top();
        pq.pop();
        ll wu = p.first;
        ll u = p.second;
        for(pair<ll, ll> q : adj[u]){
            ll wv = q.first;
            ll v = q.second;
            if(dist[u] + wv < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + wv;
                pq.push({wv, v});
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
    for(ll i=0;i<m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dijkstra(1);
    // cout << dist[n] << "\n";
    if(dist[n] == INF){
        cout << "-1\n";
        return 0;
    }
    ll p = n;
    vector<ll> path;
    while(p != -1){
        // cout << p << " ";
        path.push_back(p);
        p = parent[p];
    }
    for(auto i = path.rbegin(); i != path.rend() ; i++){
        cout << *i << " ";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}