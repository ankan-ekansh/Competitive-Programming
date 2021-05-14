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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        set<ll> s;
        for(ll i=0;i<n;i++){
            s.insert(((i+a[i])%n + n)%n);
        }
        // for(auto x : s){
        //     cout << x << " ";
        // }
        // cout << "\n";
        cout << (s.size() == n ? "YES\n" : "NO\n");
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}