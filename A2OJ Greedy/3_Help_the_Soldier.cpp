/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, t;
ll dp[7][1001];
vector<pair<ll, ll>> v[7];
const ll INF = 0x3f3f3f3f;
ll rec(ll items, ll money){
    if(money < 0){
        return 0;
    }
    if(items <= 0){
        return INF;
    }
    if(dp[items][money] != -1){
        return dp[items][money];
    }
    ll ans = 0;
    for(ll i=0;i<v[items].size();i++){
        if(money >= v[items][i].first){
            ans = max(ans, min(v[items][i].second, rec(items-1, money-v[items][i].first)));
        }
    }
    return dp[items][money] = ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // memset(dp, -1, sizeof(dp));
    cin >> n >> t;
    for(ll i=0;i<n;i++){
        ll x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
    }
    for(ll i=0;i<=t;i++){
        dp[0][i] = INF;
    }
    for(ll i=0;i<=t;i++){
        for(ll j=1;j<=6;j++){
            for(ll k=0;k<v[j].size();k++){
                if(v[j][k].first <= i){
                    dp[j][i] = max(dp[j][i], min(v[j][k].second, dp[j-1][i-v[j][k].first]));
                }
            }
        }
    }
    cout << dp[6][t] << "\n";
    // cout << rec(6, t) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}