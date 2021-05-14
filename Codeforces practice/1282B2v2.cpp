/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
        
        ll n, p, k;
        cin >> n >> p >> k;
        ll a[n+7];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        ll dp[n+7];
        ll ans = 0;
        for(ll i=0;i<n;i++){
            if(i == 0){
                dp[i] = a[i];
            }
            else if(i < k-1){
                dp[i] = dp[i-1] + a[i];
            }
            else if(i == k-1){
                dp[i] = a[i];
            }
            else{
                dp[i] = dp[i-k] + a[i];
            }
            if(dp[i] <= p){
                ans = max(ans, i+1);
            }
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}