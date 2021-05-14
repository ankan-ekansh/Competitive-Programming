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
        
        ll n, p, k;
        cin >> n >> p >> k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        ll ans = 0, pref = 0;
        for(ll i=0;i<=k;i++){
            ll sum = pref;
            if(sum > p){
                break;
            }
            ll cnt = i;
            for(ll j=i+k-1;j<n;j+=k){
                if(sum + a[j] <= p){
                    cnt += k;
                    sum += a[j];
                }
                else{
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << "\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}