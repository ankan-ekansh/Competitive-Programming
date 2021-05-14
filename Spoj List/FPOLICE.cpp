/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
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
        
        ll n, tm;
        cin >> n >> tm;
        ll tt[n+1][n+1];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                cin >> tt[i][j];
            }
        }
        ll risk[n+1][n+1];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                cin >> risk[i][j];
            }
        }
        ll dp[n+1][tm+1];
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=tm;j++){
                dp[i][j] = INF;
            }
        }
        for(ll i=0;i<=tm;i++){
            dp[1][i] = 0;
        }
        for(ll i=0;i<=tm;i++){
            for(ll j=1;j<=n;j++){
                for(ll k=1;k<=n;k++){
                    if(j == k){
                        continue;
                    }
                    if(tt[j][k] > i){
                        continue;
                    }
                    // min risk of reaching k with maximum i time
                    dp[k][i] = min(dp[k][i], risk[j][k] + dp[j][i-tt[j][k]]);       // go from j to k
                    // risk of going from j to k + risk of reaching j from any other node in (i - time[j][k]) time
                }
            }
        }
        if(dp[n][tm] == INF){
            cout << "-1\n";
        }
        else{
            for(ll i=0;i<=tm;i++){
                if(dp[n][i] == dp[n][tm]){
                    cout << dp[n][tm] << " " << i << "\n";
                    break;
                }
            }
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}