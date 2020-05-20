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
vector<ll> adj[100007];
vector<ll> dis(100007);
vector<long double> prob(100007);
void dfs(ll u = 1, ll p = -1, ll d = 0){
    if(u == 1){
        prob[1] = 1;
    }
    ll ways = adj[u].size() - 1;
    if(u == 1){
        ways++;
    }
    dis[u] = d;
    for(ll v : adj[u]){
        if(v == p){
            continue;
        }
        prob[v] = prob[u] / (long double)ways;
        dfs(v, u, d+1);
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
    
    ll n;
    cin >> n;
    for(ll i=1;i<n;i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cout << u << " " << v << "\n";
    }
    // ll paths = 0;
    // vector<ll> ending;
    // for(ll i=2;i<=n;i++){
    //     // cout << i << " : ";
    //     // for(auto j : adj[i]){
    //     //     cout << j << " " ;
    //     // }
        // cout << "\n";
    //     if(adj[i].size() == 1){
    //         // cout << i << "\n";
    //         paths++;
    //         ending.push_back(i);
    //     }
    // }
    // cout << "paths = " << paths << "\n";
    dfs();
    long double ans = 0.0;
    for(ll i=2;i<=n;i++){
        if(adj[i].size() == 1){
            ans += prob[i] * dis[i];
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}