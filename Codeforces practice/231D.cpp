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
    
    ll x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    ll x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    // x1 = 2*x1, y1 = 2*y1, z1 = 2*z1, x2 = 2*x2, y2 = 2*y2, z2 = 2*z2;
    ll a[7] = {0};
    for(ll i=1;i<=6;i++){
        cin >> a[i];
    }
    ll v[7] = {0};
    v[1] = -1, v[2] = 1, v[3] = -1, v[4] = 1, v[5] = -1, v[6] = 1;
    ll r[7] = {0};
    ll mxm = 0;
    r[1] = v[1] * (y1 - 0);
    r[2] = v[2] * (y1 - y2);
    r[3] = v[3] * (z1 - 0);
    r[4] = v[4] * (z1 - z2);
    r[5] = v[5] * (x1 - 0);
    r[6] = v[6] * (x1 - x2);
    ll ans = 0;
    for(ll i=1;i<=6;i++){
        if(r[i] > 0){
            ans += a[i];
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}