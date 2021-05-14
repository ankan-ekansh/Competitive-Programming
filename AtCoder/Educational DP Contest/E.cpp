/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, W, maxsum;
const ll INF = 1e15 + 7;
ll dp[107][100007]; // dp[N][V] - min wt for N items equal to value V
// if this min weight is <= W and V is as max as possible that is our answer
ll wt[107], val[107];
bool vis[107][100007];
// ll recur(ll n, ll v){
//     // base case
//     if(v <= 0){
//         return 0;
//     }
//     if(n == 0){
//         return INF;
//     }
//     if(vis[n][v]){
//         return dp[n][v];
//     }
//     vis[n][v] = 1;
//     return dp[n][v] = min(dp[n][v], min(recur(n-1, v), wt[n-1] + recur(n-1, v-val[n-1])));
//     // if(v >= val[n]){
//     //     return dp[n][v] = min(dp[n][v], min(recur(n+1, v), wt[n] + recur(n+1, v-val[n])));
//     // }
//     // else{
//     //     return dp[n][v] = min(dp[n][v], recur(n+1, v));
//     // }
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
        cin >> wt[i] >> val[i];
        maxsum += val[i];
    }
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=maxsum;j++){
            dp[i][j] = INF;
        }
    }
    for(ll i=0;i<=maxsum;i++){
        dp[0][i] = INF;
    }
    for(ll i=0;i<=N;i++){
        dp[i][0] = 0;
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=maxsum;j++){
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], wt[i-1] + dp[i-1][j-val[i-1]]));
        }
    }
    bool flag = false;
    for(ll V = maxsum; V >= 0; V--){
        if(dp[N][V] <= W){
            flag = true;
            // cout << dp[N][V] << " ";
            cout << V << "\n";
            break;
        }
    }
    if(!flag){
        cout << "0\n";
    }
    // for(ll i=0;i<=N;i++){
    //     for(ll j=0;j<=maxsum;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    // recur(0, maxsum);
    // bool flag = false;
    // for(ll V = maxsum; V >= 0; V--){
    //     if(recur(N, V) <= W){
    //         cout << V << "\n";
    //         flag = true;
    //         break;
    //     }
    // }
    // if(!flag){
    //     cout << "0\n";
    // }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
