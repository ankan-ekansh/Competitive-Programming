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
    
    ll n, m, k;
    cin >> n >> m >> k;
    pair<ll, ll> a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n, greater<pair<ll, ll>>());
    ll sum = 0;
    vector<ll> idx;
    for(ll i=0;i<m*k;i++){
        sum += a[i].first;
        idx.push_back(a[i].second);
    }
    sort(idx.begin(), idx.end());
    cout << sum << "\n";
    for(ll i=0;i<k-1;i++){
        cout << idx[i*m - 1 + m] + 1 << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}