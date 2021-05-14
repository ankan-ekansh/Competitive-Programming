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
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll mxm = a[n-1];
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(i > 0 && a[i] == a[i-1]){
            continue;
        }
        for(ll j=2*a[i];j<=2*mxm;j+=a[i]){
            auto it = lower_bound(a.begin(), a.end(), j);
            it--;
            // cout << *it << "\n";
            ans = max(ans, *it % a[i]);
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}