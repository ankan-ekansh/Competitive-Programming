/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
ll a[1001];
ll dp[1001][1001];
// ll solve(ll N, ll K){
//     if(N > n){
//         return 0;
//     }
//     if(K < 0){
//         return 0;
//     }
//     // return max(a[N] + solve(N+2, K-a[N]), solve(N+1, K));
//     ll ans1 = a[N] + solve(N+2, K-a[N]);
//     ll ans2 = solve(N+1, K);
//     if(max(ans1, ans2) <= k){
//         return max(ans1, ans2);
//     }
//     else if(min(ans1, ans2) <= k){
//         return min(ans1, ans2);
//     }
//     else{
//         return 0;
//     }
// }
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
    ll ct = 1;
    while(t--){
        
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        // for(ll i=0;i<=k;i++){
        //     dp[0][i] = 0;
        // }
        // for(ll i=0;i<=n;i++){
        //     dp[i][0] = 0;
        // }
        // memset(dp, 0, sizeof(dp));
        for(ll i=1;i<=k;i++){
            for(ll j=1;j<=n;j++){
                if(a[j] <= i){
                    if(j >= 3){
                        dp[j][i] = max(dp[j-1][i], a[j] + dp[j-2][i-a[j]]);
                    }
                    else{
                        dp[j][i] = max(dp[j-1][i], a[j]);
                    }
                }
                else{
                    dp[j][i] = dp[j-1][i];
                }
            }
        }
        // for(ll i=0;i<=n;i++){
        //     for(ll j=0;j<=k;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << "Scenario #" << ct++ << ": ";
        cout << dp[n][k] << "\n";
        // cout << solve(1, k) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}