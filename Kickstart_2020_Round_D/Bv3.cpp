/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100007];
ll dp[100007][4];
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
        
        ll n;
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        
        cout << "Case #" << tc++ << ": " << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}