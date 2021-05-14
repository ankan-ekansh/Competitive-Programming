/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x, k;
ll v[100007];
ll ct;
bool dp[100007];
bool vis[100007];
bool solve(ll sum, ll n, ll prev){
    // cout << sum << " " << n << " " << prev << "\n";
    if(n == k+1){
        if(sum == 0){
            return dp[sum] = true;
        }
        else{
            return dp[sum] = false;
        }
    }
    if(vis[sum]){
        return dp[sum];
    }
    ct++;
    vis[sum] = true;
    bool ans = dp[sum - prev*v[n-1]];
    for(ll i=0;i<=prev;i++){
        if(sum >= (i*v[n])){
            ans |= solve(sum-(i*v[n]), n+1, i);
        }
    }
    return dp[sum] = ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x >> k;
    for(ll i=1;i<=k;i++){
        cin >> v[i];
    }
    // cout << x/v[1] << "\n";
    cout << solve(x, 1, x/v[1]) << "\n";
    cout << ct << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}