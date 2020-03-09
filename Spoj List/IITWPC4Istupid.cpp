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
ll parent[300007], nodes, edges;
pair<ll, pair<ll, ll>> p[300007];
unordered_map<ll, ll> m;
void make_set(){
    for(ll i=0;i<300007;i++){
        parent[i] = i;
    }
}
ll root(ll x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void union_set(ll x, ll y){
    ll p = root(x);
    ll q = root(y);
    // parent[p] = parent[q];
    if(m[parent[p]] == 1 && m[parent[q]] == 0){
        parent[q] = parent[p];
        m[parent[q]] = m[parent[p]];
    }
    else if(m[parent[p]] == 0 && m[parent[q]] == 1){
        parent[p] = parent[q];
        m[parent[p]] = m[parent[q]];
    }
    else{
        parent[p] = parent[q];
        m[parent[p]] = m[parent[q]];
    }
}
ll kruskal(){
    ll x, y;
    ll cost, minimum_cost = 0;
    for(ll i=0;i<edges;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)){
            if(m[root(x)] && m[root(y)]){
                // cout << x << " " << root(x) << " : " << y << " " << root(y) << "\n";
                continue;
            }
            // cout << x << " " << root(x) << " : " << y << " " << root(y) << "\n";
            union_set(x, y);
            // cout << x << " " << root(x) << " : " << y << " " << root(y) << "\n";
            minimum_cost+=cost;
        }
    }
    return minimum_cost;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        make_set();
        m.clear();
        cin >> nodes >> edges;
        for(ll i=1;i<=nodes;i++){
            ll x;
            cin >> x;
            m[i] = x;
        }
        for(ll i=0;i<edges;i++){
            ll x, y, cost;
            cin >> x >> y >> cost;
            p[i] = make_pair(cost, make_pair(x, y));
        }
        sort(p, p+edges);
        // cout << kruskal() << "\n";
        ll ans = kruskal();
        bool flag = true;
        for(ll i=1;i<=nodes;i++){
            // cout << i << " " << parent[i] << " " << " " << m[parent[i]] << "\n";
            if(m[root(i)] == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << ans << "\n";
        }
        else{
            cout << "impossible\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}