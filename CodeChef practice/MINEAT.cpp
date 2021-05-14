/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool f(ll &n, ll &h, ll a[], ll &mid){
    ll needed = 0;
    for(ll i=0;i<n;i++){
        needed += ceil(a[i]/(double)mid);
    }
    if(needed <= h){
        return true;
    }
    return false;
}
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
        
        ll n, h;
        cin >> n >> h;
        ll a[n];
        ll start = 1, end = LLONG_MIN;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            end = max(end, a[i]);
        }
        ll mid;
        ll ans = LLONG_MAX;
        while(start <= end){
            mid = (start + end)/2;
            // mid = (start + end - 1)/2;
            if(f(n, h, a, mid)){
                ans = min(ans, mid);
                end = mid - 1;
                // end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        cout << ans << "\n";
        // cout << start << "\n";
        // if(f(n, h, a, start)){
        //     cout << start << "\n";
        // }
        // else{

        // }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}