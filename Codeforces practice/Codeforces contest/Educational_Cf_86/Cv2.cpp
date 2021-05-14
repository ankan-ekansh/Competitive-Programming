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
    int t;
    cin>>t;
    while(t--){
        
        ll a, b, q;
        cin >> a >> b >> q;
        ll prod = a * b;
        ll count[prod + 7] = {0};
        for(ll i=1;i<=prod;i++){
            count[i] = count[i-1] + ((i % a) % b != (i % b) % a);
        }
        while(q--){
            ll l, r;
            cin >> l >> r;
            cout << (r/prod) * count[prod] + count[r % prod] - (((l-1)/prod) * count[prod] + count[(l-1) % prod]) << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}