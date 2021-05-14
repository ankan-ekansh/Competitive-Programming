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
    
    ll n, m;
    cin >> n >> m;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll dp[n+2] = {0};
    for(ll i=1;i<=n;i++){
        dp[i] = dp[i-1] + a[i];
    }
    for(ll i=1;i<=n;i++){
        if(i-m >= 1){
            dp[i] += dp[i-m];
        }
    }
    for(ll i=1;i<=n;i++){
        cout << dp[i] << " ";
    }
    // cout << "\n";
    // for(ll i=1;i<=n;i++){
    //     ll j = i;
    //     ll tmp = 0;
    //     ll days = 1;
    //     while(j >= 1){
    //         tmp += dp[j];
    //         // days++;
    //         j-=m;
    //     }
    //     cout << tmp << " ";
    // }
    // cout << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}