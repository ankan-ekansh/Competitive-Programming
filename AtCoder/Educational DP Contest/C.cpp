/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll dp[1000007][3];
ll a[100007][3];
// ll rec(ll n, ll k){
//     if(n == 1){
//         ll ta = 0;
//         for(ll i=0;i<3;i++){
//             if(i == k){
//                 continue;
//             }
//             ta = max(ta, a[n][i]);
//         }
//         return ta;
//     }
//     if(dp[n][k]){
//         return dp[n][k];
//     }
//     ll ans = 0;
//     for(ll i=0;i<3;i++){
//         if(i == k){
//             continue;
//         }
//         ans = max(ans, a[n][i] + rec(n-1, i));
//     }
//     return dp[n][k] = max(dp[n][k], ans);
// }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    // cout << max(rec(n, 0), max(rec(n, 1), rec(n, 2))) << "\n";
    dp[1][0] = a[1][0], dp[1][1] = a[1][1], dp[1][2] = a[1][2];
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<3;j++){
            for(ll k=0;k<3;k++){
                if(k == j){
                    continue;
                }
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][k]);
            }
        }
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}