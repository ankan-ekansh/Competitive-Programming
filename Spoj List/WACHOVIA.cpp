#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int k, m;
        cin >> k >> m;
        int w[m+1], v[m+1];
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        for(int i=1;i<=m;i++){
            cin >> w[i] >> v[i];
        }
        int dp[m+7][k+7];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=0;j<=k;j++){
                if(j < w[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][max(j-w[i], 0)] + v[i]);
                }
            }
        }
        // for(int i=1;i<=m;i++){
        //     for(int j=0;j<=k;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << "Hey stupid robber, you can get " << dp[m][k] << ".\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
