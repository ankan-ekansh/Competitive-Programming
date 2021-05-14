/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// ll dp[1000007];
vector<ll> dp(25820);
ll fun(ll n){
    if(n <= 0){
        return dp[0] = 0;
    }
    if(n == 1){
        return dp[n] = 2;
    }
    if(dp[n]){
        return dp[n];
    }
    return dp[n] = 2*fun(n-1) - fun(n-2) + 3;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(ll i=1;i<=25820;i++){
        ll a = fun(i);
    }
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        auto it = lower_bound(dp.begin(), dp.end(), n);
        ll ctr = 0;
        while(1){
            it = lower_bound(dp.begin(), dp.end(), n);
            // cout << *it << " -> ";
            while(*it > n && *it > 0){
                it--;
            }
            // cout << *it << " = " << n << "\n";
            if(*it > 0){
                ctr++;
            }
            else{
                break;
            }
            n = n - *it;
            if(n <= 0){
                break;
            }
        }
        cout << ctr << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}