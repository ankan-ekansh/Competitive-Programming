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
        ll dp[n+7][3];
        ll p[n+7], h[n+7];
        memset(dp, 0, sizeof(dp));
        for(ll i=0;i<n;i++){
            cin >> p[i] >> h[i];
        }
        dp[0][0] = h[0];    // left
        dp[0][1] = h[0];    // right
        dp[0][2] = 0;       // center
        for(ll i=1;i<n;i++){
            ll prev1 = p[i-1];
            ll prev2 = p[i-1] + h[i-1];
            dp[i][2] = max({dp[i][2], dp[i-1][0], dp[i-1][2]});
            if(p[i] == prev1){
                dp[i][1] = max({dp[i][1], dp[i-1][0] + h[i], dp[i-1][2] + h[i]});
            }
            if(p[i] == prev2){
                dp[i][1] = max({dp[i][1], dp[i-1][1] + h[i]});
                dp[i][2] = max({dp[i][2], dp[i-1][1]});
            }
            if(p[i] - h[i] == prev1){
                dp[i][0] = max({dp[i][0], dp[i-1][0] + h[i], dp[i-1][2] + h[i]});
            }
            if(p[i] - h[i] == prev2){
                dp[i][0] = max({dp[i][0], dp[i-1][1] + h[i]});
            }
        }
        // cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans = max({ans, dp[i][0], dp[i][1], dp[n][2]});
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}