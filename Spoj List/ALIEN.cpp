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
        
        ll n, b;
        cin >> n >> b;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll i=0, j=0;
        ll ans1 = LLONG_MAX, ans2 = 0, tmp = 0;
        for(ll i=0;i<n;i++){
            // cout << i << " " << j << "\n";
            while(j < n && tmp + a[j] <= b){
                tmp += a[j];
                if(j - i + 1 > ans2){
                    ans2 = j - i + 1;
                    ans1 = tmp;
                }
                if(j - i + 1 == ans2){
                    ans1 = min(ans1, tmp);
                }
                j++;
            }
            // if(j - i > ans2 && tmp <= b){
            //     ans2 = j - i;
            //     ans1 = tmp;
            // }
            tmp -= a[i];
            // i++;
        }
        cout << ans1 << " " << ans2 << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}