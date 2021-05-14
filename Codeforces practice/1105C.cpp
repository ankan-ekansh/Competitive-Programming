/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 1e9 + 7;
ll dp[200007][3];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, l, r;
    cin >> n >> l >> r;
    ll n0, n1, n2;
    n0 = r/3 - l/3 + (l % 3 == 0);
    // n1 = (r / 3 + (r % 3 >= 1)) - (l % 3 == 0 ? l / 3 : (l % 3 == 1 ? l / 3 : l / 3 + 1));
    n1 = (r-1)/3 - (l-1)/3 + ((l-1) % 3 == 0);
    n2 = r - l + 1 - (n0 + n1);
    dp[1][0] = n0, dp[1][1] = n1, dp[1][2] = n2;
    for(ll i=2;i<=n;i++) {
        dp[i][0] = (((dp[i-1][0] * n0) % m + (dp[i-1][1] * n2) % m) % m + (dp[i-1][2] * n1) % m) % m;
        dp[i][1] = (((dp[i-1][0] * n1) % m + (dp[i-1][1] * n0) % m) % m + (dp[i-1][2] * n2) % m) % m;
        dp[i][2] = (((dp[i-1][0] * n2) % m + (dp[i-1][1] * n1) % m) % m + (dp[i-1][2] * n0) % m) % m;
    }
    cout << dp[n][0] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}