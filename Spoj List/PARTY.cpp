/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b, n;
int dp[5007][1007];
int fees[1007], fun[1007];
// int recur(int B, int N){
//     if(B == 0 || N == 0){
//         return 0;
//     }
//     if(dp[B][N]){
//         return dp[B][N];
//     }
//     if(fees[N-1] > B){
//         return dp[B][N] = max(dp[B][N], recur(B, N-1));
//     }
//     else{
//         return dp[B][N] = max(dp[B][N], max(fun[N-1] + recur(B-fees[N-1], N-1), recur(B, N-1)));
//     }
// }
// int recur2(int B, int N){
//     if(N == 0){
//         return 0;
//     }
//     if(dp[B][N] > dp[B][N-1]){
//         return fees[N-1] + recur2(B-fees[N-1], N-1);
//     }
//     else{
//         return recur2(B, N-1);
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
    
    while(1){
        cin >> b >> n;
        memset(dp, 0, sizeof(dp));
        if(b == 0 && n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> fees[i] >> fun[i];
        }
        // recur(b, n);
        // cout << cost << " " << dp[b][n] << "\n";
        // int ans = recur(b, n);
        for(int i=0;i<=b;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(fees[j-1] > i){
                    dp[i][j] = dp[i][j-1];
                }
                else{
                    dp[i][j] = max(fun[j-1] + dp[i-fees[j-1]][j-1], dp[i][j-1]);
                }
            }
        }
        // int cost = recur2(b, n);
        int cost = 0;
        int tb = b;
        // for(int i=n; i>0 && ans>0;i--){
        //     if(ans == dp[tb][i-1]){
        //         continue;
        //     }
        //     else{
        //         cost += fees[i-1];
        //         ans = ans - fun[i-1];
        //         tb = tb - fees[i-1];
        //     }
        // }
        int i=0;
        for(i=0;i<=b;i++){
            if(dp[i][n] == dp[b][n]){
                break;
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=b;j++){
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        cout << i << " " << dp[b][n] << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}