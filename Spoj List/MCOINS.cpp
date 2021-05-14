/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
// #define ll long long
using ll = long long;
using namespace std;
int n, k, l;
int dp[1000007];
int fun(int x){
    if(x <= 0){
        return 0;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    if(x-1 >= 0 && !fun(x-1)){
        return dp[x] = 1;
    }
    if(x-l >= 0 && !fun(x-l)){
        return dp[x] = 1;
    }
    if(x-k >=0 && !fun(x-k)){
        return dp[x] = 1;
    }
    return dp[x] = 0;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k >> l >> n;
    memset(dp, -1, sizeof(dp));
    string ans;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(fun(x)){
            ans += 'A';
        }
        else{
            ans += 'B';
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}