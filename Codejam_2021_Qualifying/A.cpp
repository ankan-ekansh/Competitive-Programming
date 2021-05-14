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
    ll t;
    cin >> t;
    ll tc = 1;
    while(t--) {
        cout << "Case #" << tc++ << ": ";
        ll n;
        cin >> n;
        ll l[n];
        for(ll i=0;i<n;i++) {
            cin >> l[i];
        }
        ll ans = 0;
        for(ll i=0;i<n-1;i++) {
            ll mnm = l[i];
            ll idx = i;
            for(ll j=i+1;j<n;j++) {
                if(l[j] < mnm) {
                    idx = j;
                    mnm = l[j];
                }
            }
            reverse(l+i, l+idx+1);
            // for(ll j=0;j<n;j++) {
            //     cout << l[j] << " ";
            // }
            // cout << "\n";
            // cout << (idx - i + 1) << "\n";
            // if(idx == i) {
            //     continue;
            // }
            ans += (idx - i + 1);
        }
        cout << ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}