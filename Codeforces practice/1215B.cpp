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
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> pos(n, 0), neg(n, 0);
    if(a[0] > 0){
        pos[0] = 1;
        neg[0] = 0;
    }
    else{
        pos[0] = 0;
        neg[0] = 1;
    }
    ll ansneg = neg[0];
    ll anspos = pos[0];
    for(ll i=1;i<n;i++){
        if(a[i] > 0){
            pos[i] += 1 + pos[i-1];
            neg[i] += neg[i-1];
        }
        else{
            pos[i] += neg[i-1];
            neg[i] += 1 + pos[i-1];
        }
        ansneg += neg[i];
        anspos += pos[i];
    }
    cout << ansneg << " " << anspos << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}