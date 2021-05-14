/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll x, ll y, ll z){
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}
void fun(vector<ll> &r, vector<ll> &g, vector<ll> &b, ll &ans){
    for(ll red : r){
        auto it1 = lower_bound(g.begin(), g.end(), red);
        auto it2 = upper_bound(b.begin(), b.end(), red);
        if(it1 == g.end() || it2 == b.begin()){
            continue;
        }
        it2--;
        ll green = *it1;
        ll blue = *it2;
        ans = min(ans, f(red, green, blue));
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
        
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<ll> r(nr), g(ng), b(nb);
        for(ll i=0;i<nr;i++){
            cin >> r[i];
        }
        for(ll i=0;i<ng;i++){
            cin >> g[i];
        }
        for(ll i=0;i<nb;i++){
            cin >> b[i];
        }
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ll ans = LLONG_MAX;
        fun(r, g, b, ans);
        fun(r, b, g, ans);
        fun(g, b, r, ans);
        fun(g, r, b, ans);
        fun(b, r, g, ans);
        fun(b, g, r, ans);
        cout << ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}