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
    ll a[n];
    map<ll, ll> mp;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        mp[a[i]]--;
        for(ll j=0;j<32;j++) {
            ll x = (1LL << j);
            // x = x - a[i];
            if(x - a[i] > 0 && mp[x - a[i]] > 0) {
                ans += mp[x - a[i]];
                // mp[a[i]]--;
            }
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}