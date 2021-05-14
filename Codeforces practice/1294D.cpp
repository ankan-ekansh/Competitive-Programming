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
    
    ll q, x, t = 1;
    cin >> q >> x;
    ll cnt[x] = {0};
    ll j = 0, mnm = LLONG_MAX;
    set<pair<ll, ll>> query;
    for(ll i=0;i<x;i++){
        query.insert({cnt[i], i});
    }
    while(t <= q){
        ll a;
        cin >> a;
        a = (a % x);
        query.erase({cnt[a], a});
        cnt[a]++;
        query.insert({cnt[a], a});
        cout << x*(*query.begin()).first + (*query.begin()).second << "\n";
        t++;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}