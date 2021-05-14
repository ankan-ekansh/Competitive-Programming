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
    
    vector<ll> bitcount[32];
    ll a[100007];
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<32;j++){
            if((1<<j)&a[i]){
                bitcount[j].push_back(i);
            }
        }
    }
    for(ll i=31;i>=0;i--){
        if(bitcount[i].size() == 1){
            swap(a[0], a[bitcount[i][0]]);
            break;
        }
    }
    for(ll i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}