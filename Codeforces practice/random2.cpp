/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dijkstra(ll s, ll d, ll n, vector<pair<ll, ll>> adj[]){
    vector<ll> dist(n+7, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto p : adj[u]){
            ll v = p.second;
            ll weight = p.first;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[d];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}