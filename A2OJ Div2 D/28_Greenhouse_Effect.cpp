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
    
    int n, m;
    cin >> n >> m;
    int a[n+7];
    double b[n+7];
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    int dp[n+7] = {0};
    for(int i=1;i<=n;i++){
        for(int j=a[i];j>=1;j--){
            dp[a[i]] = max(dp[a[i]], 1 + dp[j]);
        }
    }
    cout << n - *max_element(dp+1, dp+1+n) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}