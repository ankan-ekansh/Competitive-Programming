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
        ll a[n+7];
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        ll ans[n+7] = {1};
        for(ll i=1;i<=n;i++){
            ll j = 2*i;
            for(;j<=n;j+=i){
                if(a[j] > a[i]){
                    ans[j] = max(ans[j], ans[i] + 1);
                }
            }
        }
        cout << *max_element(ans+1, ans+1+n) + 1 << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}