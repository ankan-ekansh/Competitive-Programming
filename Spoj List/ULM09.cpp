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
ll parent[200007], nodes, edges;
pair<ll, pair<ll, ll>> p[200007];
void make_set(){
    for(ll i=0;i<200007;i++){
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
    parent[p] = parent[q];
}
ll kruskal(){
ll x, y;
ll cost, minimum_cost = 0;
for(ll i=0;i<edges;i++){
    x = p[i].second.first;
    y = p[i].second.second;
    cost = p[i].first;
    if(root(x) != root(y)){
        minimum_cost+=cost;
        union_set(x, y);
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
    
    while(1){
        cin >> nodes >> edges;
        if(nodes == 0 && edges == 0){
            break;
        }
        make_set();
        ll x, y;
        ll weight, cost, minimum_cost;
        ll sum = 0;
        for(ll i=0;i<edges;i++){
            cin >> x >> y >> weight;
            sum+=weight;
            p[i] = make_pair(weight, make_pair(x, y));
        }
        sort(p, p+edges);
        minimum_cost = kruskal();
        cout << sum - minimum_cost << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}