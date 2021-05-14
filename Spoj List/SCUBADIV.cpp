/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e15+7;
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
        
        ll nn, on;
        cin >> on >> nn;
        ll n;
        cin >> n;
        ll oc[n+1], nc[n+1], w[n+1];
        ll dp[n+1][on+1][nn+1];
        for(ll i=1;i<=n;i++){
            cin >> oc[i] >> nc[i] >> w[i];
        }
        for(ll i=0;i<=on;i++){
            for(ll j=0;j<=nn;j++){
                dp[0][i][j] = INF;
            }
        }
        dp[0][0][0] = 0;
        for(ll ox=0;ox<=on;ox++){
            for(ll ni=0;ni<=nn;ni++){
                for(ll items=1;items<=n;items++){
                    dp[items][ox][ni] = min(dp[items-1][ox][ni], w[items] + dp[items-1][max(0LL, ox-oc[items])][max(0LL, ni-nc[items])]);
                }
            }
        }
        cout << dp[n][on][nn] << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}