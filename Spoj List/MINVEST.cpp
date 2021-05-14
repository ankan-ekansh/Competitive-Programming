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
        
        ll amount, year;
        cin >> amount >> year;
        ll rem = amount % 1000;
        amount/=1000;
        ll n;
        cin >> n;
        ll cost[n+1], intrst[n+1];      // weight, value
        for(ll i=1;i<=n;i++){
            cin >> cost[i] >> intrst[i];
            cost[i]/=1000;      // as cost is a multiple of 1000
        }
        // ll ans = 0;
        for(ll i=1;i<=year;i++){
            ll dp[amount+1];
            memset(dp, 0, sizeof(dp));
            // dp[0] = 0;
            ll profit = 0;
            for(ll j=1;j<=amount;j++){
                for(ll k=1;k<=n;k++){
                    if(cost[k] <= j){
                        dp[j] = max(dp[j], intrst[k] + dp[j-cost[k]]);
                    }
                }
            }
            profit = dp[amount];
            amount += (profit+rem)/1000;
            rem = (profit + rem)%1000;
        }
        cout << amount*1000 + rem << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
