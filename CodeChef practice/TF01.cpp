/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
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
        
        int n, k;
        cin >> n >> k;
        bool dp[n+1][k+1];
        // memset(dp, false, sizeof(dp));
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0 && j != 0){
                    dp[i][j] = false;
                }
                else if(i != 0 && j == 0){
                    dp[i][j] = true;
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=k;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(a[i-1] <= j){
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << dp[n][k] << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}