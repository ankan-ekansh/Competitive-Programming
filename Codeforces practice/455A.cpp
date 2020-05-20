#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t n;
    cin >> n;
    int64_t a[n];
    map<int64_t, int64_t> c;
    int64_t m = 0;
    for(int64_t i=0;i<n;i++){
        cin >> a[i];
        c[a[i]]++;
        m = max(m, a[i]);
    }
    int64_t dp[100005]={0};
    dp[0] = 0;
    dp[1] = c[1];
    for(int64_t i=2;i<=m;i++){
        dp[i] = max(dp[i-1], dp[i-2] + i*c[i]);
    }
    cout << dp[m] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}