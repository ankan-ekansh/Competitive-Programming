/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll h, w;
    cin >> h >> w;
    char a[h+1][w+1];
    for(ll i=1;i<=h;i++){
        string s;
        cin >> s;
        for(ll j=0;j<w;j++){
            a[i][j+1] = s[j];
        }
    }
    ll dp[h+1][w+1];
    memset(dp, 0, sizeof(dp));
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(i == 1 && j == 1){
                dp[i][j] = 1;
            }
            if(a[i][j] == a[i-1][j] && a[i][j] == '.'){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            }
            if(a[i][j] == a[i][j-1] && a[i][j] == '.'){
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
        }
    }
    cout << dp[h][w] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}