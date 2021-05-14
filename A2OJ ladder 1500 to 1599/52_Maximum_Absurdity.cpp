/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum(ll l, ll r, ll pref[]){
    return (l == 0) ? pref[r] : (pref[r] - pref[l-1]);
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
    ll ar[n];
    for(ll i=0;i<n;i++){
        cin >> ar[i];
    }
    ll pref[n];
    memset(pref, 0, sizeof(pref));
    int a = 0, b = 0;
    pref[0] = ar[0];
    for(ll i=1;i<n;i++){
        pref[i] = pref[i-1] + ar[i];
    }
    pair<ll, ll> ans = {n - 2*k, n - k};
    ll mxm = sum(n - 2*k, n - k - 1, pref) + sum(n-k, n-1, pref);
    pair<ll, ll> suffmxm = {n-k, sum(n-k, n-1, pref)};
    for(ll i=n-2*k-1;i>=0;i--){
        ll cur = sum(i+k, i+2*k-1, pref);
        if(cur >= suffmxm.second){
            suffmxm = {i+k, cur};
        }
        cur = sum(i, i+k-1, pref) + suffmxm.second;
        if(cur >= mxm){
            mxm = cur;
            ans = {i, suffmxm.first};
        }
    }
    
    cout << ans.first+1 << " " << ans.second+1 << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}