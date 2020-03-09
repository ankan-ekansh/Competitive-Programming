#include<bits/stdc++.h>
#define ll long long    
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t = 1;
    while(1){
        ll n;
        cin >> n;
        if(n == 0){
            break;
        }
        ll dp[n+9][5];
        memset(dp, 0, sizeof(dp));
        ll a[n+9][5];
        memset(a, 0, sizeof(a));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }
        //dp[1][1] = a[1][1];
        dp[1][1] = 1000000000;
        dp[1][2] = a[1][2];
        dp[1][3] = a[1][3] + dp[1][2];
        // for(ll i=n-1;i>=1;i--){
        //     for(ll j=3;j>=1;j--){
        //         //dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], min(dp[i+1][j], dp[i+1][j-1]))) + a[i][j];
        //         if(j == 1){
        //             dp[i][j] = min(dp[i][j+1] + a[i][j], min(dp[i+1][j+1] + a[i][j], dp[i+1][j] + a[i][j]));
        //         }
        //         else if(j == 2){
        //             dp[i][j] = min(dp[i][j+1] + a[i][j], min(dp[i+1][j+1] + a[i][j], min(dp[i+1][j] + a[i][j], dp[i+1][j-1] + a[i][j])));
        //         }
        //         else{
        //             dp[i][j] = min(dp[i+1][j-1] + a[i][j], dp[i+1][j] + a[i][j]);
        //         }
        //     }
        // }
        for(ll i=2;i<=n;i++){
            for(ll j=1;j<=3;j++){
                //dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], min(dp[i+1][j], dp[i+1][j-1]))) + a[i][j];
                if(j == 1){
                    dp[i][j] = min(dp[i-1][j+1] + a[i][j], dp[i-1][j] + a[i][j]);
                }
                else if(j == 2){
                    dp[i][j] = min(dp[i][j-1] + a[i][j], min(dp[i-1][j-1] + a[i][j], min(dp[i-1][j] + a[i][j], dp[i-1][j+1] + a[i][j])));
                }
                else{
                    dp[i][j] = min(dp[i][j-1] + a[i][j], min(dp[i-1][j-1] + a[i][j], dp[i-1][j] + a[i][j]));
                }
            }
        }
        // for(ll i=1;i<=n;i++){
        //     for(ll j=1;j<=3;j++){
        //         //dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], min(dp[i+1][j], dp[i+1][j-1]))) + a[i][j];
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << t << ". " << dp[n][2] << "\n";
        t++;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}