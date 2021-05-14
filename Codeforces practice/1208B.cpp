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
    for(ll i=0;i<n;i++) {
        cin >> a[i];
    }
    set<ll> s;
    ll ans = n-1;
    for(ll i=0;i<n;i++) {
        bool flag = true;
        for(ll j=0;j<i;j++) {
            if(s.count(a[j])) {
                flag = false;
                break;
            }
            s.insert(a[j]);
        }
        ll idx = n;
        for(ll j=n-1;j>=i;j--) {
            if(!s.count(a[j])) {
                idx = j;
                s.insert(a[j]);
            }
            else {
                break;
            }
        }
        if(flag) {
            ans = min(ans, idx-i);
        }
        s.clear();
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}