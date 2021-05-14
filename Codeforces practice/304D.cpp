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
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    // set<ll> s;
    // s.insert(a[0]);
    vector<ll> s;
    s.push_back(a[0]);
    ll ans = s.size();
    for(ll i=1;i<n;i++){
        if(a[i] > *s.rbegin()){
            // s.insert(a[i]);
            s.push_back(a[i]);
        }
        else{
            auto it = lower_bound(s.begin(), s.end(), a[i]);
            if(it != s.end()){
                // s.erase(*it);
                // s.insert(a[i]);
                s[it - s.begin()] = a[i];
            }
        }
        ans = max(ans, (ll)s.size());
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}