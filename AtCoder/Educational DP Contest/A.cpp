/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int dp[100007];
int h[100007];
const int INF = 1e9+7;
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
    return dp[n] = min(abs(h[n] - h[n-1]) + recur(n-1), abs(h[n] - h[n-2]) + recur(n-2));
    // int ans1 = INT_MAX, ans2 = INT_MAX;
    // if(n == 2){
    //     ans1 = abs(h[2] - h[1]);
    // }
    // else if(n == 3){
    //     ans1 = abs(h[3] - h[1]);
    //     ans2 = abs(h[3] - h[2]) + recur(2);
    // }
    // else{
    //     ans1 = abs(h[n] - h[n-2]) + recur(n-2);
    //     ans2 = abs(h[n] - h[n-1]) + recur(n-1);
    // }
    // return dp[n] = min(ans1, ans2);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    // memset(dp, -1, sizeof(dp));
    for(int i=0;i<100007;i++){
        dp[i] = INF;
    }
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    recur(n);
    cout << dp[n] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}