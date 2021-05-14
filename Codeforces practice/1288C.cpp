/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll dp[2077][2077];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(ll i=1;i<=n+2*m-1;i++){
        dp[i][0] = 1;
        for(ll j=1;j<=2*m;j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
        }
    }
    cout << dp[n+2*m-1][2*m] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}