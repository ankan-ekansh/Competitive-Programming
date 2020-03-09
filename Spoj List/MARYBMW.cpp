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
ll nodes, edges, parent[100007];
pair<ll, pair<ll, ll>> p[100007];
ll minspeed = LLONG_MAX;
void make_set(){
    for(ll i=0;i<=100000;i++){
        parent[i] = i;
    }
}
ll find_parent(ll x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void union_set(ll x, ll y){
    ll a = find_parent(x);
    ll b = find_parent(y);
    parent[a] = parent[b];
}
bool kruskal(){
    ll x, y, speed;
    for(ll i=edges-1;i>=0;i--){
        x = p[i].second.first;
        y = p[i].second.second;
        speed = p[i].first;
        if(find_parent(x) != find_parent(y)){
            union_set(x, y);
            // cout << x << " " << y << " " << speed << "\n";
            if(find_parent(1) == find_parent(nodes)){
                cout << speed << "\n";
                return true;
            }
            // minspeed = min(minspeed, speed);
        }
    }
    // if(find_parent(1) == find_parent(nodes)){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    return false;
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
        minspeed = LLONG_MAX;
        cin >> nodes >> edges;
        for(ll i=0;i<edges;i++){
            ll a, b, c;
            cin >> a >> b >> c;
            p[i] = make_pair(c, make_pair(a, b));
        }
        sort(p, p+edges);
        bool flag = kruskal();
        // if(flag){
        //     cout << minspeed << "\n";
        // }
        // else{
        //     cout << "-1\n";
        // }
        if(!flag){
            cout << "-1\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}