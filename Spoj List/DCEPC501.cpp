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
 
        long long n;
        cin >> n;
        long long a[n + 10];
        memset(a, 0, sizeof(a));
        long long dp[n + 10];
        for(long long i=0;i<n;i++){
            cin >> a[i];
        }
        memset(dp, 0, sizeof(dp));
        for(long long i=n-1;i>=0;i--){
            dp[i] = max(a[i]+dp[i+2], max(a[i]+a[i+1]+dp[i+4], a[i]+a[i+1]+a[i+2]+dp[i+6]));
        }
        cout << dp[0] << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}