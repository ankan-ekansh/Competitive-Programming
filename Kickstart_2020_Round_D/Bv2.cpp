/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10007];
ll dp[100007][4];
ll fun(ll n, ll p, char c){
    if(n <= 0){
        return 0;
    }
    // cout << n << " " << a[n-1] << " " << p << " " << c << "\n";
    if(dp[n][c-'A'] != 1000007){
        return dp[n][c-'A'];
    }
    if(a[n-1] > p){
        if(c == 'A'){
            return dp[n][0] = min({dp[n][0], 1LL + fun(n-1, a[n-1], 'A'), fun(n-1, a[n-1], 'B'), fun(n-1, a[n-1], 'C'), fun(n-1, a[n-1], 'D')});
        }
        else if(c == 'B'){
            return dp[n][1] = min({dp[n][1], 1LL + fun(n-1, a[n-1], 'A'), 1LL + fun(n-1, a[n-1], 'B'), fun(n-1, a[n-1], 'C'), fun(n-1, a[n-1], 'D')});
        }
        else if(c == 'C'){
            return dp[n][2] = min({dp[n][2], 1LL + fun(n-1, a[n-1], 'A'), 1LL + fun(n-1, a[n-1], 'B'), 1LL + fun(n-1, a[n-1], 'C'), fun(n-1, a[n-1], 'D')});
        }
        else{
            return dp[n][3] = min({dp[n][3], 1LL + fun(n-1, a[n-1], 'A'), 1LL + fun(n-1, a[n-1], 'B'), 1LL + fun(n-1, a[n-1], 'C'), 1LL + fun(n-1, a[n-1], 'D')});
        }
    }
    else if(a[n-1] < p){
        if(c == 'A'){
            return dp[n][0] = min({dp[n][0], 1LL + fun(n-1, a[n-1], 'A'), 1LL + fun(n-1, a[n-1], 'B'), 1LL + fun(n-1, a[n-1], 'C'), 1LL + fun(n-1, a[n-1], 'D')});
        }
        else if(c == 'B'){
            return dp[n][1] = min({dp[n][1], fun(n-1, a[n-1], 'A'), 1LL + fun(n-1, a[n-1], 'B'), 1LL + fun(n-1, a[n-1], 'C'), 1LL + fun(n-1, a[n-1], 'D')});
        }
        else if(c == 'C'){
            return dp[n][2] = min({dp[n][2], fun(n-1, a[n-1], 'A'), fun(n-1, a[n-1], 'B'), 1LL + fun(n-1, a[n-1], 'C'), 1LL + fun(n-1, a[n-1], 'D')});
        }
        else{
            return dp[n][3] = min({dp[n][3], fun(n-1, a[n-1], 'A'), fun(n-1, a[n-1], 'B'), fun(n-1, a[n-1], 'C'), 1LL + fun(n-1, a[n-1], 'D')});
        }
    }
    else{
        ll tmp = 0x3f3f3f3f;
        for(int i=0;i<4;i++){
            if((char)('A'+i) == c){
                tmp = min(tmp, fun(n-1, a[n-1], c));
            }
            else{
                tmp = min(tmp, 1 + fun(n-1, a[n-1], (char)('A' + i)));
            }
        }
        return dp[n][c-'A'] = min(dp[n][c-'A'], tmp);
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
    int t;
    cin>>t;
    int tc = 1;
    while(t--){
        
        ll n;
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<4;j++){
                dp[i][j] = 1000007;
            }
        }
        // memset(dp, -1, sizeof(dp));
        // ll a1 = fun(n, -1, 'A');
        // ll a2 = fun(n, -1, 'B');
        // ll a3 = fun(n, -1, 'C');
        // ll a4 = fun(n, -1, 'D');
        // ll a5 = fun(n, 1000001, 'A');
        // ll a6 = fun(n, 1000001, 'B');
        // ll a7 = fun(n, 1000001, 'C');
        // ll a8 = fun(n, 1000001, 'D');
        ll a1 = fun(n-1, a[n-1], 'A');
        ll a2 = fun(n-1, a[n-1], 'B');
        ll a3 = fun(n-1, a[n-1], 'C');
        ll a4 = fun(n-1, a[n-1], 'D');
        cout << "Case #" << tc++ << ": ";
        cout << min({a1, a2, a3, a4}) << "\n";
        // cout << min({a1, a2, a3, a4, a5, a6, a7, a8}) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}