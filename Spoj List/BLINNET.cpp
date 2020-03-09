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
ll nodes, edges, parent[1000007];
pair<ll, pair<ll, ll>> p[1000007];
void make_set(){
    for(ll i=0;i<1000007;i++){
        parent[i] = i;
    }
}
ll find_parent(ll x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void union_set(ll a, ll b){
    ll x = find_parent(a);
    ll y = find_parent(b);
    parent[x] = parent[y];
}
ll kruskal(){
    ll minimum_cost = 0, cost, x, y;
    for(ll i=0;i<edges;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // cout << x << " " << y << "Weight : " << cost << "\n";
        if(find_parent(x) != find_parent(y)){
            // cout << x << " " << y << "\n";
            union_set(x, y);
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
 
        cin >> nodes;
        make_set();
        edges = 0;
        for(ll i=1;i<=nodes;i++){
            string s;
            cin >> s;
            ll r;
            cin >> r;
            ll x, weight;
            for(ll j=1;j<=r;j++){
                cin >> x >> weight;
                p[edges++] = make_pair(weight, make_pair(i, x));
            }
        }
        sort(p, p+edges);
        // for(ll i=0;i<edges;i++){
        //     cout << p[i].second.first << " - " << p[i].second.second << ", Weight = " << p[i].first << "\n";
        // }
        cout << kruskal() << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}