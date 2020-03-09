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
    long long t;
    cin>>t;
    long long c = 0;
    while(t--){
 
        long long n;
        cin >> n;
        long long a[n+1];
        for(long long i=1;i<=n;i++){
            cin >> a[i];
        }
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        cout << "Case " << ++c <<": ";
        if(n == 0){
            cout << "0" << "\n";
        }
        else if(n == 1){
            cout << a[1] << "\n";
        }
        else if(n == 2){
            cout << max(a[1], a[2]) << "\n";
        }
        else{
            dp[1] = a[1];
            dp[2] = max(a[1], a[2]);
            for(long long i=3;i<=n;i++){
                dp[i] = max(dp[i-1], a[i] + dp[i-2]);
            }
            cout << dp[n] << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}