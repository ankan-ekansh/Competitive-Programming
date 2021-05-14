/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
ll grid[1007][1007];
ll n, m;
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
        
        cin >> n >> m;
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                cin >> grid[i][j];
            }
        }
        ans=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if (grid[i][j] == 1) {
                    ll l = 0, r = 0, u = 0, d = 0;
                    for(ll k = i; k < n; k++) {
                        if(grid[k][j] == 1)
                            d++;
                        else
                            break;
                    }
                    for(ll k = i; k >= 0; k--){
                        if(grid[k][j] == 1)
                            u++;
                        else
                            break;
                    }
                    for (ll k = j; k < m; k++){
                        if(grid[i][k] == 1)
                            r++;
                        else
                            break;
                    }
                    for (ll k = j; k >= 0; k--){
                        if(grid[i][k] == 1)
                            l++;
                        else
                            break;
                    }
                    // cout << l << " " << u << " " << r << " " << d << "\n";
                    for(ll k = 2; k <= d; k++){
                        if(l >= 2 * k)
                            ans++;
                        if(r >= 2 * k)
                            ans++;
                    }
                    for(ll k = 2; k <= r; k++){
                        if(u >= 2 * k)
                            ans++;
                        if(d >= 2 * k)
                            ans++;
                    }
                    for(ll k = 2; k <= l; k++){
                        if(u >= 2 * k)
                            ans++;
                        if(d >= 2 * k)
                            ans++;
                    }
                    for(ll k = 2; k <= u; k++){
                        if(l >= 2 * k)
                            ans++;
                        if(r >= 2 * k)
                            ans++;
                    }
                }
            }
        }
        cout << "Case #" << tc++ << ": " << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        // cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}