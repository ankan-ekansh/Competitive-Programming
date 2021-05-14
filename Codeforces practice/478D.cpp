/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll dp[200007];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll r, g;
    cin >> r >> g;
    ll h=1;
    for(ll i=1;;i++){
        if((i*(i+1))/2 <= r+g && ((i+1)*(i+2))/2 > r+g){
            h = i;
            break;
        }
    }
    dp[0] = 1;
    for(ll i=1;i<=h;i++){
        for(ll j=r;j>=i;j--){
            dp[j] += dp[j-i];
            if(dp[j] >= mod){
                dp[j] -= mod;
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<=r;i++){
        if(i+g >= h*(h+1)/2){
            ans += dp[i];
            if(ans >= mod){
                ans -= mod;
            }
        }
    }
    cout << (ans + mod) % mod << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}