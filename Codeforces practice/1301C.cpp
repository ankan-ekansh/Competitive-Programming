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
        
        ll n, m;
        cin >> n >> m;
        ll ans = (n*(n+1))/2;
        ll x = (n-m) / (m+1);
        ll y = (n-m) % (m+1);
        // cout << ans << " " << x << " " << y << "\n";
        ans -= y*((x+1)*(x+2))/2;
        ans -= (m+1-y)*((x*(x+1))/2);
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}