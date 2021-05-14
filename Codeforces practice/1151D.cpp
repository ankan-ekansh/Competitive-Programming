/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<ll, ll> p, pair<ll, ll> q){
    return (p.first - p.second) > (q.first - q.second);
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
    vector<pair<ll, ll>> v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    ll ans = 0;
    // for(ll i=0;i<n;i++){
    //     cout << v[i].first << " " << v[i].second << "\n";
    // }
    for(ll i=0;i<n;i++){
        ans += (n*v[i].second - v[i].first) + (v[i].first - v[i].second)*(i+1);
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}