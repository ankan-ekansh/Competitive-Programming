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
    // int t;
    // cin>>t;
    // while(t--){
 
        int n, k;
        cin >> n >> k;
        int a[n+1], b[n+1];
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        int c[n+1], d[n+1], dp[n+1];
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(dp, 0, sizeof(dp));

        c[1] = a[1];
        d[1] = b[1];
        dp[1] = min(c[1], d[1]);
        int count = 0;
        for(int i=2;i<=n;i++){
            c[i] = min(c[i-1] + a[i], d[i-1] + b[i] + a[i]);
            d[i] = min(d[i-1] + b[i], c[i-1] + a[i] + b[i]);
            dp[i] = min(c[i], d[i]);
            count = i;
            // cout << dp[i] << "\n";
            if(dp[i] > k){
                break;
            }
        }
        if(count == n){
            cout << count << " " << dp[count] << "\n";
        }
        else{
            cout << count-1 << " " << dp[count-1] << "\n";
        }
 
//    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}