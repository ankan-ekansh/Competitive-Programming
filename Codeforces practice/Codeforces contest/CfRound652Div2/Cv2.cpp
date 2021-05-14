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
        
        ll n, k;
        cin >> n >> k;
        ll a[n], b[k];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        for(ll i=0;i<k;i++){
            cin >> b[i];
        }
        sort(a, a+n, greater<ll>());
        sort(b, b+k);
        ll sum = 0;
        for(ll i=0;i<k;i++){
            sum += a[i];    // maximum of k groups
            if(b[i] == 1){
                sum += a[i];    // minimum of the group size = 1
            }
            b[i]--;     // 1 selected, now need to pick one less from successively decreasing array
        }
        ll idx = k;
        for(ll i=0;i<k;i++){
            if(b[i] > 0){
                sum += a[idx+(b[i]-1)];     // minimum element of the group of size b[i] will be at idx + b[i] - 1
                // a[idx], a[idx+1], a[idx+2], ..., a[idx + b[i] - 1] will be the remaining elements to pick among which
                // a[idx+b[i]-1] is the least
                idx += b[i];    // next group will take elements from a[idx+b[i]]
            }
        }
        cout << sum << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}