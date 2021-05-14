/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9 + 7;
int n, k;
int dp[100007], h[100007];
int recur(int n){
    if(n <= 0){
        return INF;
    }
    if(n == 1){
        return 0;
    }
    if(dp[n] != INF){
        return dp[n];
    }
    int ans = INF;
    for(int i=1;i<=k && (n-i >= 0);i++){
        // return dp[n] = min(dp[n], abs(h[n] - h[n-i]) + recur(n-i));
        ans = min(ans, abs(h[n] - h[n-i]) + recur(n-i));
    }
    return dp[n] = min(ans, dp[n]);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // int n, k;
    cin >> n >> k;
    // int dp[n+7];
    for(int i=0;i<n+7;i++){
        dp[i] = INF;
    }
    // int h[n+7];
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    recur(n);
    cout << dp[n] << "\n";
    // dp[0] = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<=i+k;j++){
    //         if(j < n){
    //             dp[j] = min(dp[j], abs(h[j] - h[i]) + dp[i]);
    //         }
    //     }
    // }
    // cout << dp[n-1] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}