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
ll n, m;
long double ans;
vector<pair<ll, ll>> adj[100007];
long double dijkstra(ll s, ll d){
    vector<long double> prob(100007, 0.0);
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair(1, s));
    prob[s] = 1;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto p : adj[u]){
            ll v = p.second;
            ll w = p.first;
            if(prob[v] < prob[u]*(((long double)w)/100)){
                prob[v] = prob[u]*(((long double)w)/100);
                pq.push(make_pair(w, v));
            }
        }
    }
    return prob[d];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        cin >> m;
        for(ll i=0;i<=n;i++){
            adj[i].clear();
        }
        ans = 0.0;
        for(ll i=1;i<=m;i++){
            ll a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back(make_pair(w, b));
            adj[b].push_back(make_pair(w, a));
        }
        cout << fixed << setprecision(6) << dijkstra(1, n)*100 << " percent" << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}