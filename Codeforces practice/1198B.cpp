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
    ll a[n+7] = {0}, b[n+7] = {0};
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll q;
    cin >> q;
    ll mx = 0;
    ll c[q+7] = {0};
    for(ll i=0;i<q;i++){
        ll qt;
        cin >> qt;
        if(qt == 1){
            ll p, x;
            cin >> p >> x;
            p--;
            a[p] = x;   // set value of pth person to x
            b[p] = i;   // set last query index of pth person
        }
        else{
            ll x;
            cin >> x;
            c[i] = x;   // set value for ith query
        }
    }
    for(ll i=q-1;i>=0;i--){
        c[i] = max(c[i], c[i+1]);   // max value to right of ith query including ith query
    }
    for(ll i=0;i<n;i++){
        cout << max(a[i], c[b[i]]) << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}