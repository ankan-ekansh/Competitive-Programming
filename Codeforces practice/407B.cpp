/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
const ll m = 1e9+7;
using namespace std;
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
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll dp[n+7] = {0};
    ll pf[n+7] = {0};
    for(ll i=1;i<=n;i++){
        dp[i] = ((2 + pf[i-1])%m - (pf[a[i] - 1] % m) + m) % m;
        pf[i] = (pf[i-1] + dp[i]) % m;
    }
    ll s = 0;
    for(ll i=1;i<=n;i++){
        s = (s + dp[i])%m;
    }
    cout << s % m << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}