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
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll q;
        cin >> q;
        while(q--){
            ll x, y;
            cin >> x >> y;
            auto it = lower_bound(a.begin(), a.end(), x+y);
            if(it == a.end()){
                cout << a.size() << "\n";
            }
            else if(*it == (x+y)){
                cout << "-1\n";
            }
            else{
                cout << it - a.begin() << "\n";
            }
        }

        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}