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
        ll a[n+7];
        ll totsum = 0;
        for(ll i=1;i<=n;i++){
            cin >> a[i];
            totsum += a[i];
        }
        bool dp[n+7][totsum+7];
        for(ll i=0;i<=n;i++){
            dp[i][0] = true;
        }
        for(ll i=1;i<=totsum;i++){
            dp[0][i] = false;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=totsum;j++){
                if(a[i] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        ll ans = 0;
        for(ll i=0;i<=totsum;i++){
            if(dp[n][i]){
                ans += i;
            }
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}