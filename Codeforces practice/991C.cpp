/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool fun(ll k){
    ll v = 0, tmp = n;
    while(tmp > 0){
        // v += k;
        v += (tmp >= k) ? k : tmp;
        tmp -= (tmp >= k) ? k : tmp;
        // tmp /= 10;
        tmp = tmp - (tmp/10);
    }
    // if(v >= (n/2)){
    //     return true;
    // }
    // return false;
    if(2*v >= n){
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
    
    cin >> n;
    ll l = 1, r = n;
    ll mid;
    ll ans = n;
    while(l < r){
        mid = (l + r)/2;
        bool res = fun(mid);
        if(res){
            // ans = min(ans, mid);
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << l << "\n";
    // cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}