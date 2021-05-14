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
        ll mxm = -1, ans = 0;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<n;i++){
            if(i != n-1){
                if(a[i] > mxm && a[i] > a[i+1]){
                    ans++;
                }
                mxm = max(mxm, a[i]);
            }
            else{
                if(a[i] > mxm){
                    mxm = a[i];
                    ans++;
                }
            }
        }
        cout << "Case #" << tc++ << ": " << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}