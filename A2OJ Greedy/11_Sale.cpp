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
    
    ll n, m;
    cin >> n >> m;
    vector<ll> neg;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        if(x < 0){
            neg.push_back(x);
        }
    }
    sort(neg.begin(), neg.end());
    ll ans = 0;
    for(ll i=0;i<neg.size() && i < m;i++){
        ans += abs(neg[i]);
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}