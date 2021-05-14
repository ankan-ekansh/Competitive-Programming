/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
#define strimng string
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
        
        strimng a[2];
        cin >> a[0];
        cin >> a[1];
        ll n = a[0].length();
        ll ans = 0, rem = 0;
        for(ll i=0;i<n;i++){
            ll ok = (a[0][i] == '0') + (a[1][i] == '0');
            if(rem + ok >= 3){  // when prev col had ok cells and was unused, now we include with current column's ok cells
                rem = rem + ok - 3;
                ans++;
            }
            else{
                rem = ok;   // when prev col and curr col ok cells are not enough to place Bishwock, then in next iteration current ok is the rem
            }
        }
        cout << ans << "\n";
        
    // }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}