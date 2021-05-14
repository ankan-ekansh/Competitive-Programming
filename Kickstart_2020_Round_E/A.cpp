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
    int tc = 1;
    while(t--){
        
        cout << "Case #" << tc++ << ": ";
        ll n;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll ans = 0, diff = a[1] - a[0], len = 1;
        for(ll i=1;i<n-1;i++){
            if((a[i+1] - a[i]) == diff){
                len++;
            }
            else{
                ans = max(ans, len);
                len = 1;
                diff = a[i+1] - a[i];
            }
        }
        ans = max(ans, len);
        cout << ans + 1 << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}