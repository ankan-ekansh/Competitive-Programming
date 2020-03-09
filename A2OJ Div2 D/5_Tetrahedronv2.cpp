#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n;
ll mod = 1e9+7;
ll dp[10000001][4];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][3] = 1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=3;j++){
            for(ll k=0;k<=3;k++){
                if(j != k){
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
                }
            }
        }
    }
    cout << dp[n][3] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}