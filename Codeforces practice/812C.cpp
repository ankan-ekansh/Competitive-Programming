/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100007], b[100007], n, s;
ll fun(ll k){
    for(ll i=0;i<n;i++){
        b[i] = a[i] + (i+1)*k;
    }
    sort(b, b+n);
    ll sum = 0;
    for(ll i=0;i<k;i++){
        sum += b[i];
    }
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll l=0, r=n+1, ans = 0, cost = 0, mid;
    while(l < r){
        mid = l + (r-l)/2;
        // cout << l << " " << mid << " " << r << "\n";
        if(fun(mid) <= s){
            ans = mid;
            cost = fun(mid);
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    cout << ans << " " << cost << "\n";
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}