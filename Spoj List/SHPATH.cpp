#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
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
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
 
        ll n;
        cin >> n;
        vector<pair<ll, ll>> adj[n+7];
        string s;
        unordered_map<string, ll> m;
        for(int i=1;i<=n;i++){
            cin >> s;
            m[s] = i;
            ll r;
            cin >> r;
            for(int j=1;j<=r;j++){
                ll v, cost;
                cin >> v >> cost;
                adj[i].push_back(make_pair(cost, v));
            }
        }
        ll q;
        cin >> q;
        for(ll i=1;i<=q;i++){
            string s1, s2;
            cin >> s1 >> s2;
            ll s = m[s1];
            ll d = m[s2];
            cout << dijkstra(s, d, n, adj) << "\n";
        }
        // for(ll i=1;i<=n;i++){
        //     cout << "City = " << i << "\n";
        //     for(auto x : adj[i]){
        //         cout << "Cost = " <<x.first << " Neighbour = " << x.second << "\n";
        //     }
        // }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}