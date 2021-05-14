/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a, ll b){
    return (a * b) / (__gcd(a, b));
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
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    // sort(a+1, a+1+n);
    ll g[n+7] = {1};
    g[n] = a[n];
    for(ll i=n-1;i>=1;i--){
        g[i] = __gcd(g[i+1], a[i]);
    }
    // for(ll i=1;i<=n;i++){
    //     cout << g[i] << " ";
    // }
    // cout << "\n";
    vector<ll> v;
    for(ll i=1;i<=n;i++){
        v.push_back(lcm(a[i], g[i+1]));
    }
    ll ans = v[0];
    for(ll i=1;i<v.size();i++){
        ans = __gcd(ans, v[i]);
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}