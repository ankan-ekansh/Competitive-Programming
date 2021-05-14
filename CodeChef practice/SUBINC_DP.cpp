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
        
        ll n;
        cin >> n;
        ll a[n], b[n] = {0};
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<n;i++){
            if(i == 0){
                b[i] = 1;
            }
            else{
                if(a[i] >= a[i-1]){
                    b[i] = b[i-1] + 1;
                }
                else{
                    b[i] = 1;
                }
            }
        }
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans += b[i];
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}