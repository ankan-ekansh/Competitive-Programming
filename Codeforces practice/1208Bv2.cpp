/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2007;
ll n;
vector<ll> a(N);
bool fun(ll s) {
    unordered_map<ll, ll> mp;
    for(ll i=0;i<n;i++) {
        mp[a[i]]++;
    }
    for(ll i=0;i<s;i++) {
        mp[a[i]]--;
        if(!mp[a[i]]) {
            mp.erase(a[i]);
        }
    }
    if(mp.size() == n - s) {
        return true;
    }
    for(ll i=s;i<n;i++) {
        mp[a[i-s]]++;
        mp[a[i]]--;
        if(!mp[a[i]]) {
            mp.erase(a[i]);
        }
        if(mp.size() == n - s) {
            return true;
        }
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
    }
    ll l=0, r=n-1, mid;
    ll ans = n-1;
    while(l < r) {
        mid = l + (r-l)/2;
        if(fun(mid)) {
            ans = min(ans, mid);
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
