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
 
        int n;
        cin >> n;
        int a[n+9][n+9];
        memset(a, 0, sizeof(a));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin >> a[i][j];
            }
        }
        int dp[n+9][n+9];
        memset(dp, 0, sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = max(a[i][j] + dp[i+1][j], a[i][j] + dp[i+1][j+1]);
            }
        }
        cout << dp[0][0] << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}