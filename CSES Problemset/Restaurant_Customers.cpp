/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     // freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    vector<pair<ll, bool>> a;
    for(ll i=0;i<n;i++){
        ll s, e;
        cin >> s >> e;
        a.push_back({s, true});
        a.push_back({e, false});
    }
    sort(a.begin(), a.end());
    ll ctr = 0, ans = 0;
    for(ll i=0;i<a.size();i++){
        ctr += (a[i].second) ? 1 : -1;
        ans = max(ans, ctr); 
    }
    cout << ans << "\n";

    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}