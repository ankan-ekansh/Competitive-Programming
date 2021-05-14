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
    
    ll l, r;
    cin >> l >> r;
    if(l == r){
        cout << "0\n";
        return 0;
    }
    ll idx = 0;
    for(ll i=63;i>=0;i--){
        if((r & (1LL << i)) && !(l & (1LL << i))){
            idx = i;
            break;
        }
        else if(!(r & (1LL << i)) && (l & (1LL << i))){
            idx = i;
            break;
        }
    }
    // cout << idx << "\n";
    ll a = (1LL << (idx));
    ll b = a - 1;
    // cout << a << " " << b << "\n";
    cout << (a ^ b) << "\n";
    // cout << (a - 1) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}