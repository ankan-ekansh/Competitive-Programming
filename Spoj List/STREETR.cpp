#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
 
        int64_t n;
        cin >> n;
        // int64_t a[n];
        int64_t g = 0;

        int64_t a, b, s = INT64_MAX, l = 0;
        cin >> b;
        s = min(s, b);
        l = max(l, b);
        for(int64_t i=1;i<n;i++){
            cin >> a;
            s = min(s, a);
            l = max(l, a);
            g = __gcd(g, a - b);
            b = a;
        }
        cout << ((l - s)/g) - n + 1 << "\n";

        // for(int64_t i=0;i<n;i++){
        //     cin >> a[i];
        //     // g = __gcd(a[i], g);
        // }
        // for(int64_t i=0;i<n-1;i++){
        //     g = __gcd(a[i+1] - a[i], g);
        // }
        // int64_t ans = 0;

        // // for(int64_t i=0;i<n-1;i++){
        // //     int64_t temp = a[i+1] - a[i];
        // //     ans+=(temp/g - 1);
        // // }

        // ans = ((a[n-1] - a[0])/g) - n + 1;

        // cout << g << "\n";
        // cout << ans << "\n";
    // }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}