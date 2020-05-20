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
vector<ll> sz;
vector<ll> parent;
vector<vector<ll>> cnt;
// void make(ll n){
//     for(ll i=0;i<=n;i++){
//         parent[i] = i;
//         sz[i] = 1;
//     }
// }
ll find_root(ll u){
    // while(u != parent[u]){
    //     parent[u] = parent[parent[u]];
    // }
    // return u;
    if(u == parent[u]){
        return u;
    }
    return parent[u] = find_root(parent[u]);
}
void union_set(ll a, ll b){
    a = find_root(a);
    b = find_root(b);
    if(a != b){
        // parent[b] = a;
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        for(ll i=0;i<26;i++){
            cnt[a][i] += cnt[b][i];
        }
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
    int t;
    cin>>t;
    while(t--){
 
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        // make(n);
        sz.assign(n+7, 0);
        parent.assign(n+7, 0);
        cnt.assign(n+7, vector<ll>(26));
        for(ll i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
            cnt[i][s[i]-'a']++;
        }
        // for(ll i=0;i<n;i++){
        //     if(find_root(i) != find_root(n-1-i))
        //         union_set(i, n-1-i);
        // }
        for(ll i=0;i<n;i++){
            // if(i != i%k){
                // if(find_root(i) != find_root(i%k)){
                //     union_set(i, i%k);
                // }
                // if(find_root(i) != find_root(i%k))
                if(i < n-i-1)
                    union_set(i, n-1-i);
                if(i+k < n)
                    union_set(i, i+k);
            // }
        }
        // for(ll i=0;i<n;i++){
        //     // ll x = i;
        //     // cout << x << " : ";
        //     // while(x != parent[x]){
        //     //     x = parent[x];
        //     //     cout << x << " ";
        //     // }
        //     // cout << "\n";
        //     cout << i << " " << parent[i] << "\n";
        // }
        ll ans = 0;
        for(ll i=0;i<n;i++){
            if(parent[i] == i){
                ll ct = 0;
                for(ll j=0;j<26;j++){
                    ct = max(ct, cnt[i][j]);
                }
                ans += sz[i] - ct;
            }
        }
        cout << ans << "\n";
        
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}