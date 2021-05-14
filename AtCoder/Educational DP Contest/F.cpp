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
    
    string s, t;
    cin >> s >> t;
    ll m = s.length(), n = t.length();
    ll dp[m+1][n+1];
    for(ll i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    for(ll i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    ll i = m, j = n;
    string lcs;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    for(char c : lcs){
        cout << c;
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}