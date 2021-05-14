/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double PI = acos(-1.0);
long double angle(pair<ll, ll> p1, pair<ll, ll> p2){
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    long double res = 180.0 / PI * atan2((x1*y2 - x2*y1), (x1*x2 + y1*y2));
    return res < 0 ? 360 + res : res;
}
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
    vector<long double> v;
    for(ll i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        v.push_back(180.0 / PI * atan2(x, y));
    }
    sort(v.begin(), v.end());
    long double ans = v[n-1] - v[0];
    for(ll i=0;i<n;i++){
        ans = min(ans, 360 - v[(i+1) % n] + v[i]);
    }
    cout << fixed << setprecision(10) << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}