/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll x, ll y, ll z){
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
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
        ll i = 0, j = 0, k = 0;
        while(i+1 < nr || j+1 < ng || k+1 < nb){
            ans = min(ans, f(r[i], g[j], b[k]));
            ll a1 = LLONG_MAX, a2 = LLONG_MAX, a3 = LLONG_MAX;
            if(i+1 < nr){
                a1 = f(r[i+1], g[j], b[k]);
            }
            if(j+1 < ng){
                a2 = f(r[i], g[j+1], b[k]);
            }
            if(k+1 < nb){
                a3 = f(r[i], g[j], b[k+1]);
            }
            if(a1 <= a2 && a1 <= a3){
                i++;
            }
            else if(a2 <= a1 && a2 <= a3){
                j++;
            }
            else{
                k++;
            }
        }
        ans = min(ans, f(r[i], g[j], b[k]));
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}