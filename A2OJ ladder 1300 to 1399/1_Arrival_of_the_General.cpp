/*
    Accepted
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    ll mi = LLONG_MAX, ma = 0, mi_pos = 0, ma_pos = 0;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        if(a[i] <= mi){
            mi = a[i];
            mi_pos = i;
        }
        if(a[i] > ma){
            ma = a[i];
            ma_pos = i;
        }
    }
    //cout<<ma_pos<<" "<<mi_pos<<"\n";
    if(mi_pos > ma_pos)
        cout<<ma_pos + (n - 1 - mi_pos)<<"\n";
    else
        cout<<ma_pos + (n - 1 - (mi_pos + 1))<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}