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
        cin >> a[0];
        ll mxm = a[0], mnm = a[0];
        for(ll i=1;i<n;i++){
            cin >> a[i];
            mnm = min(mnm, a[i]);
            mxm = max(mxm, a[i]);
        }
        sort(a.begin(), a.end());
        ll ans = mxm * mnm;
        vector<ll> b;
        ll tmp = ans;
        for(ll i=2;i*i<=tmp;i++){
            if(tmp % i == 0){
                b.push_back(i);
                if(i != tmp/i){
                    b.push_back(tmp/i);
                }
            }
        }
        sort(b.begin(), b.end());
        if(a == b){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}