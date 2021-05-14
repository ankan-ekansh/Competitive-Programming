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
    int t;
    cin>>t;
    while(t--){
        
        ll n, x, m;
        cin >> n >> x >> m;
        ll l = x, r = x;
        ll ans = 1;
        for(ll i=0;i<m;i++){
            ll cl, cr;
            cin >> cl >> cr;
            if(cr < l || cl > r){
                continue;
            }
            l = min(l, cl);
            r = max(r, cr);
            ans = max(ans, r-l+1);
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}