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
vector<ll> adj[200007];
vector<ll> par(200007), dis(200007), tin(200007), tout(200007);
ll timer = 0;
void dfs(ll x = 1, ll p = -1, ll d = 0){
    dis[x] = d;
    par[x] = p;
    tin[x] = timer++;
    for(ll u : adj[x]){
        if(u == p){
            continue;
        }
        dfs(u, x, d+1);
    }
    tout[x] = timer++;
}
bool isAncestor(ll u, ll v){
    if(tin[u] <= tin[v] && tout[u] >= tout[v])
        return true;
    return false;
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
    for(ll i=0;i<n-1;i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    for(ll i=0;i<m;i++){
        ll u, v, k;
        cin >> k;
        vector<ll> q;
        // vector<ll> q(k);
        // for(ll j=0;j<k;j++){
        //     cin >> q[j];
        // }
        for(ll i=0;i<k;i++){
            ll tmp;
            cin >> tmp;
            q.push_back(tmp);
        }
        v = q[0];
        for(ll j=0;j<k;j++){
            if(dis[v] < dis[q[j]]){
                v = q[j];
            }
        }
        for(ll j=0;j<k;j++){
            if(q[j] != v && par[q[j]] != -1){
                q[j] = par[q[j]];
            }
        }
        // v = q[q.size() - 1];
        bool flag = true;
        for(ll j=0;j<k;j++){
            if(q[j] == v){
                continue;
            }
            if(!isAncestor(q[j], v)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}