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
    ll a[n+7] = {0};
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll pref[n+7] = {0};
    for(ll i=1;i<=n;i++){
        pref[i] = a[i] + (a[i]-1)*(i-1);
        // cout << a[i] + (a[i]-1)*(i-1) << "\n";
    }
    // for(ll i=1;i<=n;i++){
    //     cout << i << " " << pref[i] << "\n";
    // }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans += pref[i];
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}