/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, W;
ll w[107], v[107];
ll dp[107][100007];
// ll rec(ll N, ll W){
//     if(N == 0 || W == 0){
//         return 0;
//     }
//     if(dp[N][W]){
//         return dp[N][W];
//     }
//     if(W >= w[N-1]){
//         return dp[N][W] = max(dp[N][W], max(rec(N-1, W), v[N-1] + rec(N-1, W-w[N-1])));
//     }
//     else{
//         return dp[N][W] = max(dp[N][W], rec(N-1, W));
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
    
    cin >> N >> W;
    for(ll i=0;i<N;i++){
        cin >> w[i] >> v[i];
    }
    // rec(N, W);
    // cout << dp[N][W] << "\n";
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=W;j++){
            if(j >= w[i-1]){
                dp[i][j] = max(dp[i][j], max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]));
            }
            else{
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
    }
    cout << dp[N][W] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}