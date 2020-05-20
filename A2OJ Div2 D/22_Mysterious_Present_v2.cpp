/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int dp[5007], w[5007], h[5007], nxt[5007];
vector<int> v;
int fun(int idx){
    if(dp[idx]){
        return dp[idx];
    }
    for(int i=1;i<=n;i++){
        if(h[i] > h[idx] && w[i] > w[idx]){
            if(fun(i) >= dp[idx]){
                dp[idx] = dp[i] + 1;
                nxt[idx] = i;
            }
        }
    }
    return dp[idx];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=0;i<5001;i++){
        dp[i] = 0;
        nxt[i] = -1;
    }
    for(ll i=0;i<=n;i++){
        cin >> w[i] >> h[i];
    }
    cout << fun(0) << "\n";
    ll idx = nxt[0];
    while(idx != -1){
        cout << idx << " ";
        idx = nxt[idx];
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}