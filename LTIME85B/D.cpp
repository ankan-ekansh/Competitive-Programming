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
        long double g[n], a[n], b[n];
        long double val1 = 0, val2 = 0;
        for(ll i=0;i<n;i++){
            cin >> g[i] >> a[i] >> b[i];
            val1 += (g[i]/(a[i] + b[i])) * b[i];
            val2 += (g[i]/(a[i] + b[i])) * a[i];
        }
        cout << fixed << setprecision(6) << val1 << " ";
        cout << fixed << setprecision(6) << val2 << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}