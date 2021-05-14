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
        
        ll n, k;
        cin >> n >> k;
        ll a[n], b[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<k;i++){
            cin >> b[i];
        }
        sort(a, a+n, greater<ll>());
        sort(b, b+k);
        ll sum = 0;
        ll idx = 0;
        for(ll i=0;i<k;i++){
            ll x = b[i];
            // sum += a[idx+x-1] + a[n-idx-1];
            sum += a[idx] + a[idx+x-1];
            idx = idx + x;
        }
        cout << sum << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}