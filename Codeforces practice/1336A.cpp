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
vector<ll> adj[200007];
vector<ll> depth(200007), subtreesize(200007);
void dfs(ll cnode, ll par){
    depth[cnode] = depth[par] + 1;
    for(ll nnode : adj[cnode]){
        if(nnode != par){
            dfs(nnode, cnode);
            subtreesize[cnode]++;
        }
    }
    subtreesize[par] += subtreesize[cnode];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;
    for(ll i=0;i<n-1;i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(ll i=1;i<=n;i++){
    //     cout << i << " " << depth[i] << " " << subtreesize[i] << "\n";
    // }
    dfs(1, 0);
    vector<ll> ans;
    for(ll i=1;i<=n;i++){
        // cout << i << " " << depth[i]-1 << " " << subtreesize[i] << "\n";
        ans.push_back(depth[i]-1 - subtreesize[i]);
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    ll s = 0;
    // for(ll i=0;i<n;i++){
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    for(ll i=0;i<k;i++){

        s += ans[i];
    }
    cout << s << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}