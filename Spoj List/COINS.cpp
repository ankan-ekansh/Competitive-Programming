/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
unordered_map<ll, ll> dp;
ll divide(ll n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    if(n == 4){
        return 4;
    }
    if(dp[n]){
        return dp[n];
    }
    return dp[n] = max(n, divide(n/2) + divide(n/3) + divide(n/4));
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // n = 2;
    // cout << divide(n) << "\n";
    while(cin >> n){
        cout << divide(n) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}