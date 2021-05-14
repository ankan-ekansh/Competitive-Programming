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
        if(n > 69){
            cout << "NO\n";
            continue;
        }
        set<ll> s;
        for(ll i=0;i<n;i++){
            ll c = 0;
            for(ll j=i;j<n;j++){
                c |= a[j];
                s.insert(c);
            }
        }
        if(s.size()*2 == n*(n+1)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}