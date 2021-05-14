/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const ll NMAX = 5007;
ll n, k, q;
ll dp[NMAX][NMAX];
ll dp2[NMAX];
ll a[NMAX];

ll fun(ll idx, ll r){
    if(idx < 0 || idx >= n){
        return 0;
    }
    if(r == 0){
        return 1;
    }
    if(dp[idx][r] != -1){
        return dp[idx][r];
    }
    dp[idx][r] = ( fun(idx-1, r-1) + fun(idx+1, r-1) ) % mod;
    return dp[idx][r];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> q;
    memset(dp, -1, sizeof(dp));
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=k;j++){
            dp2[i] = (dp2[i] + (fun(i, j) * fun(i, k-j)) % mod) % mod;
        }
        ans = (ans + (a[i] * dp2[i]) % mod) % mod;
    }
    for(ll i=0;i<q;i++){
        ll idx, x;
        cin >> idx >> x;
        idx--;
        ll d = (x - a[idx] + mod) % mod;
        ans = (ans + (d * dp2[idx]) % mod) % mod;
        cout << ans << "\n";
        a[idx] = x;
    }
    
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}