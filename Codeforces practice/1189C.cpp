/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
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
    vector<ll> a(n+1, 0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<ll> dp(n+1, 0);
    for(ll i=1;i<=n;i++){
        dp[i] = dp[i-1] + a[i];
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << (dp[r] - dp[l-1])/10 << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}