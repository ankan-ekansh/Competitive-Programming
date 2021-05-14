/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const string rgb = "RGB";
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
        
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ans = LLONG_MAX;
        for(ll j=0;j<3;j++) {
            ll a[n+1];
            memset(a, 0, sizeof(a));
            a[0] = (s[0] != rgb[(j)%3]);
            for(ll i=1;i<n;i++) {
                a[i] = a[i-1] + (s[i] != rgb[(i + j)%3]);
                if(i == k-1) {
                    ans = min(ans, a[i]);
                }
                else if(i >= k) {
                    ans = min(ans, a[i] - a[i-k]);
                }
            }
            if(n-1-k < 0) {
                ans = min(ans, a[n-1]);
            }
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}