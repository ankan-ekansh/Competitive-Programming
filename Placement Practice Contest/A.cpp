/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll dp[10000001];
void fun(ll n){
    dp[0] = 1;
    for(ll i=0;i<=n;i++){
        if(i >= 2){
            dp[i] = (dp[i] % mod + dp[i-2] % mod) % mod;
        }
        if(i >= 3){
            dp[i] = (dp[i] % mod + dp[i-3] % mod) % mod;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fun(10000000);
    // for(ll i=0;i<=10;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;
        
        // ll dp[n+7] = {0};
        // dp[0] = 1;
        // // dp[2] = dp[3] = 1;
        // for(ll i=0;i<=n;i++){
        //     dp[i] = (dp[max(i-2LL, 0LL)] % mod + dp[max(i-3LL, 0LL)] % mod) % mod;
        // }
        // cout << dp[n] << "\n";
        // cout << fun(n) << "\n";
        // fun(n);
        cout << dp[n] << "\n";
        
    }
    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}