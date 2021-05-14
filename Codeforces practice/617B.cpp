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
    ll a[n];
    ll n1 = 0, n0 = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]){
            n1++;
        }
        else{
            n0++;
        }
    }
    // cout << n0 << " " << n1 << "\n";
    if(!n1){
        cout << "0\n";
    }
    else{
        ll ans = 1;
        ll prev = -1;
        for(ll i=0;i<n;i++){
            if(a[i] == 1){
                if(prev != -1){
                    ans = ans * (i - prev);
                }
                prev = i;
            }
        }
        cout << ans << "\n";
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}