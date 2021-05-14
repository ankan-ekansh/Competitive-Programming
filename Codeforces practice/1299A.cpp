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
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll pref[n+7] = {0}, suff[n+7] = {0};
    for(ll i=1;i<=n;i++){
        if(i == 1){
            pref[i] = ~a[i];
        }
        else{
            pref[i] = (pref[i-1] & (~a[i]));
        }
    }
    for(ll i=n;i>=1;i--){
        if(i == n){
            suff[i] = ~a[i];
        }
        else{
            suff[i] = (suff[i+1] & (~a[i]));
        }
    }
    ll mxm = 0;
    ll idx = 1;
    for(ll i=1;i<=n;i++){
        ll temp = 0;
        if(i == 1){
            temp = a[1] & suff[2];
        }
        else if(i == n){
            temp = pref[n-1] & a[n];
        }
        else{
            temp = pref[i-1] & a[i] & suff[i+1];
        }
        if(temp > mxm){
            idx = i;
            mxm = temp;
        }
    }
    cout << a[idx] << " ";
    for(ll i=1;i<idx;i++){
        cout << a[i] << " ";
    }
    for(ll i=idx+1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}