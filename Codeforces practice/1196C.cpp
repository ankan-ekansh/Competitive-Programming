/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 100000;
ll mxmx, mnmx, mxmy, mnmy;
void fun(ll x, ll y, ll l, ll u, ll r, ll d) {
    if(!l) {
        mnmx = max(mnmx, x);
    }
    if(!r) {
        mxmx = min(mxmx, x);
    }
    if(!u) {
        mxmy = min(mxmy, y);
    }
    if(!d) {
        mnmy = max(mnmy, y);
    }
}
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
        
        ll n;
        cin >> n;
        mnmx = mnmy = -INF;
        mxmx = mxmy = INF;
        if(n == 1) {
            ll x, y, l, u, r, d;
            cin >> x >> y >> l >> u >> r >> d;
            cout << "1 " << x << " " << y << "\n";
            continue;
        }
        for(ll i=0;i<n;i++) {
            ll x, y, l, r, u, d;
            cin >> x >> y >> l >> u >> r >> d;
            fun(x, y, l, u, r, d);
        }
        if(mnmx <= mxmx && mnmy <= mxmy) {
            cout << "1 " << mnmx << " " << mnmy << "\n";
        }
        else {
            cout << "0\n";
        }
        
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}