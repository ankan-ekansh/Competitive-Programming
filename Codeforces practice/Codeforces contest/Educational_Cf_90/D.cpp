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
        ll a[n+7] = {0};
        ll totsum = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            if(i % 2 == 0){
                totsum += a[i];
                a[i] = (-1ll)*a[i];
            }
        }
        // for(ll i=0;i<n;i++){
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
        ll max_so_far1 = INT_MIN, sum1 = 0;
        for(ll i=0;i<n;i+=2){
            sum1 = sum1 + a[i] + a[i+1];
            // cout << sum1 << "\n";
            if(sum1 < 0){
                sum1 = 0;
            }
            if(max_so_far1 < sum1){
                max_so_far1 = sum1;
            }
        }
        ll sum2 = 0;
        ll max_so_far2 = INT_MIN;
        for(ll i=2;i<n;i+=2){
            sum2 = sum2 + a[i] + a[i-1];
            // cout << sum2 << "\n";
            if(sum2 < 0){
                sum2 = 0;
            }
            if(max_so_far2 < sum2){
                max_so_far2 = sum2;
            }
        }
        // cout << totsum << " " << sum << "\n";
        // cout << max_so_far1 << " " << max_so_far2 << "\n";
        cout << totsum + max(max_so_far1, max_so_far2) << "\n";

        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}