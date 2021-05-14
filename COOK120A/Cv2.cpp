/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[107];
vector<ll> a(107);
vector<ll> primes;
vector<ll> val(2, 1);
bool p[107];
void sieve(){
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for(ll i=2;i*i<=100;i++){
        if(p[i]){
            for(ll j=i*i;j<=100;j+=i){
                p[j] = false;
            }
        }
    }
    for(ll i=2;i<=100;i++){
        if(p[i]){
            primes.push_back(i);
        }
    }
}
void dfs(ll u, ll p, ll x){
    a[u] = val[x&1];
    for(ll v : adj[u]){
        if(v == p){
            continue;
        }
        dfs(v, u, 1-x);
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
    sieve();
    // ll idx = 0;
    // for(ll i=2;idx < 2 && i<=100;i++){
    //     if(p[i]){
    //         // cout << i << " ";
    //         ll tmp = val[idx] * i;
    //         if((tmp < 0) && idx < 1){
    //             // cout << "\n";
    //             idx++;
    //             val[idx] = i;
    //         }
    //         else if(tmp > 0){
    //             val[idx] *= i;
    //         }
    //     }
    // }
    // cout << "\n";
    val[0] = 1518410187442699518, val[1] = 1518409177581024365;
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;
        for(ll i=0;i<=n;i++){
            adj[i].clear();
            a[i] = 1;
        }
        for(ll i=0;i<n-1;i++){
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // cout << val[0] << " " << val[1] << "\n";
        dfs(1, 0, 0);
        for(ll i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        // cout << 2e18 - val[0] << " " << 2e18 - val[1] << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}