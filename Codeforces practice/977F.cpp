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
    
    int n;
    cin >> n;
    int a[n];
    map<int, int> dp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[a[i]] = max(dp[a[i]], dp[a[i]-1] + 1);
    }
    int l = 0, last = 0;
    for(int i=0;i<n;i++){
        // l = max(l, dp[a[i]]);
        if(l < dp[a[i]]){
            l = dp[a[i]];
            last = a[i];
        }
    }
    vector<int> ans;
    cout << l << "\n";
    for(int i=n-1;i>=0;i--){
        if(a[i] == last){
            last--;
            ans.push_back(i+1);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}