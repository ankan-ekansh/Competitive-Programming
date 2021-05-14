/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool f(ll n, ll k, ll v){
    ll s = 0;
    do{
        s += v;
        v = v / k;
    }
    while(v > 0);
    if(s >= n){
        return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    ll mid;
    ll ans = LLONG_MAX;
    while(l <= r){
        mid = (l + r)/2;
        bool check = f(n, k, mid);
        if(check){
            ans = min(ans, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}