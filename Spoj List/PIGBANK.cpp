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
        
        ll e, f;
        cin >> e >> f;
        ll n;
        cin >> n;
        ll W = f - e;
        ll v[n+7], w[n+7];
        for(ll i=0;i<n;i++){
            cin >> v[i] >> w[i];
            // v[i] = -v[i];
        }
        ll dp[f+7];
        for(ll i=0;i<=W;i++){
            dp[i] = 99999999999;
        }
        dp[0] = 0;
        for(ll i=1;i<=W;i++){
            for(ll j=0;j<n;j++){
                if(i >= w[j]){
                    dp[i] = min(dp[i], v[j] + dp[i-w[j]]);
                }
            }
        }
        if(dp[W] != 99999999999){
            // cout << dp[W] << "\n";
            cout << "The minimum amount of money in the piggy-bank is " << dp[W] << ".\n";
        }
        else{
            // cout << "-1\n";
            cout << "This is impossible.\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}