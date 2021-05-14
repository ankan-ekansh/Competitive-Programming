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
    int tc = 1;
    while(t--){
        
        ll n;
        cin >> n;
        ll a[n];
        ll inc = 0, dec = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<n-1;i++){
            if(a[i] < a[i+1]){
                inc++;
            }
            if(a[i] > a[i+1]){
                dec++;
            }
        }
        ll ans = 0;
        ll x = 0;
        ll prev = a[0];
        ll curr;
        for(ll i=1;i<n;i++){
            curr = a[i];
            if(prev > curr){
                x = 0;
            }
            else if(curr > prev && x < 3){
                x++;
            }
            else if(curr > prev && x == 3){
                x = 0;
                ans++;
            }
            prev = curr;
        }
        cout << "Case #" << tc++ << ": " << ans << "\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}