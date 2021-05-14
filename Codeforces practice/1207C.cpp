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
        
        ll n, a, b;
        cin >> n >> a >> b;
        vector<vector<ll>> dp(n+1, vector<ll>(3, (ll)1e18));
        string s;
        cin >> s;
        dp[0][1] = b;
        for(ll i=0;i<n;i++) {
            if(s[i] == '0') {
                // ith block can either be at height 1 or 2
                dp[i+1][1] = min({dp[i+1][1], dp[i][1] + a + b, dp[i][2] + 2*a + b});
                dp[i+1][2] = min({dp[i+1][2], dp[i][2] + a + 2*b, dp[i][1] + 2*a + 2*b});
            }
            else {
                // ith block can only be at height 2
                dp[i+1][2] = min({dp[i+1][2], dp[i][2] + a + 2*b});
            }
        }
        cout << dp[n][1] << "\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}