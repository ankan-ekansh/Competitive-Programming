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
        
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        // multiset<ll> s;
        map<ll, ll> mp;
        for(ll i=0;i<n;i++){
            if(a[i] % k == 0){
                continue;
            }
            else{
                ll x = a[i] / k;
                ll y = (x+1)*k - a[i];
                // if(s.count(y)){
                //     y = y + k;
                //     s.insert(y);
                // }
                // ll z = s.count(y);
                ll z = mp[y];
                // s.insert(y + k*z);
                mp[y + k*z]++;
                if(z != 0){
                    // s.insert(y);
                    mp[y]++;
                }
                // while(s.count(y)){
                //     y = y + k;
                // }
                // auto it = lower_bound(s.begin(), s.end(), y);
                // y = y + (s.count(k)+1)*k;
                // s.insert(y);
            }
        }
        // cout << *s.rbegin() << "\n";
        // cout << s.size() << "\n";
        // if(s.size() == 0){
        //     cout << "0\n";
        //     continue;
        // }
        // cout << *max_element(s.begin(), s.end()) + 1 << "\n";
        if(mp.size() == 0){
            cout << "0\n";
        }
        else{
            cout << (*mp.rbegin()).first + 1 << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}