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
        
        ll n;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll ans = n;
        ll l=0;
        for(ll i=0;i<n-1;i++){
            l++;
            if(a[i] > a[i+1]){
                ans += (l*(l-1))/2;
                l = 0;
            }
        }
        ans += (l*(l+1))/2;
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}