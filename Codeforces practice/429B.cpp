/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    ll a[n+7][m+7];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    ll dp[4][n+7][m+7];
    memset(dp, 0, sizeof(dp));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            // top left to i, j
            dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]) + a[i][j];
        }
        for(ll j=m;j>=1;j--){
            // top right to i, j
            dp[1][i][j] = max(dp[1][i-1][j], dp[1][i][j+1]) + a[i][j];
        }
    }
    for(ll i=n;i>=1;i--){
        for(ll j=1;j<=m;j++){
            // bottom left to i, j
            dp[2][i][j] = max(dp[2][i+1][j], dp[2][i][j-1]) + a[i][j];
        }
        for(ll j=m;j>=1;j--){
            // bottom right to i, j
            dp[3][i][j] = max(dp[3][i][j+1], dp[3][i+1][j]) + a[i][j];
        }
    }
    for(ll i=0;i<=n+1;i++){
        for(ll j=0;j<4;j++){
            dp[j][i][0] = dp[j][i][m+1] = -INF;
        }
    }
    for(ll i=0;i<=m+1;i++){
        for(ll j=0;j<4;j++){
            dp[j][0][i] = dp[j][n+1][i] = -INF;
        }
    }
    // for(ll i=0;i<=n+1;i++){
    //     for(ll j=0;j<=m+1;j++){
    //         cout << dp[1][i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll tmp = dp[0][i][j-1] + dp[1][i-1][j] + dp[2][i+1][j] + dp[3][i][j+1];
            ans = max(ans, tmp);
            tmp = dp[0][i-1][j]+dp[3][i+1][j]+dp[2][i][j-1]+dp[1][i][j+1];
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}